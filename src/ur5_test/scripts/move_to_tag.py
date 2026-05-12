#!/usr/bin/env python3
"""
move_to_tag.py

ROS 2 node that looks up the pose of AR tag `tag_12` in the TF tree and sends a
goal to the `/move_gripper` action server to move the UR5 end effector to the
tag's (x, y) coordinates at a fixed height of z = 0.45 m.

If the action server returns `success = False` (e.g. planning failed), the node
will retry — up to MAX_ATTEMPTS total — re-querying the tag's TF each time so
that the latest tag pose is used.

Assumes a MoveGripper action interface with the following definition:

    # Goal
    float64 x
    float64 y
    float64 z
    bool use_default_z
    ---
    # Result
    bool success
    string message
    ---
    # Feedback
    string status
"""

import sys

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.duration import Duration

import tf2_ros
from tf2_ros import TransformException

from ur5_test.action import MoveGripper


TAG_FRAME = "tag_12"
WORLD_FRAME = "world"
TARGET_Z = 0.45
MAX_ATTEMPTS = 5
RETRY_DELAY_SEC = 1.0  # short pause between attempts


class MoveToTagNode(Node):
    def __init__(self):
        super().__init__("move_to_tag")

        # TF2 listener
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # Action client
        self.action_client = ActionClient(self, MoveGripper, "/move_gripper")

        # State
        self._goal_handle = None
        self._result_future = None
        self._attempt = 0
        self._retry_timer = None

        # Kick off the work shortly after construction, once TF has had a
        # chance to populate the buffer.
        self._startup_timer = self.create_timer(1.0, self._startup_callback)

    def _startup_callback(self):
        """Run once: wait for the action server, then begin the attempt loop."""
        self._startup_timer.cancel()

        self.get_logger().info("Waiting for /move_gripper action server...")
        if not self.action_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().error("/move_gripper action server not available; shutting down.")
            rclpy.shutdown()
            return

        self._try_once()

    def _try_once(self):
        """Look up the tag, build a goal, and send it. Called once per attempt."""
        self._attempt += 1
        self.get_logger().info(f"Attempt {self._attempt} of {MAX_ATTEMPTS}.")

        # Look up the tag transform (re-queried each attempt so latest pose is used)
        try:
            transform = self.tf_buffer.lookup_transform(
                WORLD_FRAME,
                TAG_FRAME,
                rclpy.time.Time(),            # latest available
                timeout=Duration(seconds=5.0),
            )
        except TransformException as ex:
            # TF failures are NOT retried per the configured policy.
            self.get_logger().error(
                f"Could not transform {TAG_FRAME} -> {WORLD_FRAME}: {ex}"
            )
            rclpy.shutdown()
            return

        x = transform.transform.translation.x
        y = transform.transform.translation.y
        self.get_logger().info(
            f"Tag {TAG_FRAME} in {WORLD_FRAME}: x={x:.4f}, y={y:.4f}; "
            f"sending goal at z={TARGET_Z:.4f}"
        )

        goal_msg = MoveGripper.Goal()
        goal_msg.x = float(x)
        goal_msg.y = float(y)
        goal_msg.z = float(TARGET_Z)
        goal_msg.use_default_z = False

        send_future = self.action_client.send_goal_async(
            goal_msg, feedback_callback=self._feedback_callback
        )
        send_future.add_done_callback(self._goal_response_callback)

    def _goal_response_callback(self, future):
        self._goal_handle = future.result()
        if not self._goal_handle.accepted:
            # Per the configured policy, rejections are NOT retried.
            self.get_logger().error("Goal was rejected by the action server.")
            rclpy.shutdown()
            return

        self.get_logger().info("Goal accepted; waiting for result...")
        self._result_future = self._goal_handle.get_result_async()
        self._result_future.add_done_callback(self._result_callback)

    def _feedback_callback(self, feedback_msg):
        status = feedback_msg.feedback.status
        self.get_logger().info(f"Feedback: {status}")

    def _result_callback(self, future):
        result = future.result().result
        if result.success:
            self.get_logger().info(f"Move succeeded: {result.message}")
            rclpy.shutdown()
            return

        # Planning / execution failure — retry if we have attempts left.
        self.get_logger().warn(
            f"Move failed on attempt {self._attempt}: {result.message}"
        )

        if self._attempt >= MAX_ATTEMPTS:
            self.get_logger().error(
                f"Giving up after {MAX_ATTEMPTS} attempts."
            )
            rclpy.shutdown()
            return

        self.get_logger().info(
            f"Retrying in {RETRY_DELAY_SEC:.1f}s..."
        )
        # Schedule the next attempt via a one-shot timer. Re-queries TF inside
        # _try_once, so the most recent tag pose is used.
        self._retry_timer = self.create_timer(RETRY_DELAY_SEC, self._retry_callback)

    def _retry_callback(self):
        # One-shot: cancel and destroy the timer, then kick off another attempt.
        self._retry_timer.cancel()
        self.destroy_timer(self._retry_timer)
        self._retry_timer = None
        self._try_once()


def main(args=None):
    rclpy.init(args=args)
    node = MoveToTagNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if rclpy.ok():
            node.destroy_node()
            rclpy.shutdown()


if __name__ == "__main__":
    sys.exit(main() or 0)