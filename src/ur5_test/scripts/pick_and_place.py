#!/usr/bin/env python3
"""
Pick-and-place sequence using ROS 2 action clients.

Sequence:
  1. Move gripper above object
  2. Move gripper to grasping position
  3. Close gripper
  4. Move to dropoff location
  5. Open gripper (drop object)

Move commands retry up to MAX_RETRIES times on failure.
"""

import sys
import time

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from control_msgs.action import GripperCommand
from ur5_test.action import MoveGripper


# --- Tunables ---------------------------------------------------------------
MAX_RETRIES = 3                 # retries per move command on failure
RETRY_DELAY_SEC = 1.0           # wait between retries
SERVER_WAIT_TIMEOUT_SEC = 10.0  # how long to wait for action servers

# Poses (x, y, z)
ABOVE_OBJECT = (-0.62, 0.0, 0.55)
GRASP_POSE   = (-0.62, 0.0, 0.35)
DROPOFF_POSE = ( 0.62, 0.0, 0.40)

# Fallback pose used if a move fails all retries
SAFE_POSE    = ( 0.0, 0.3, 0.4)

# Gripper positions
GRIPPER_CLOSED = 0.0
GRIPPER_OPEN   = 0.025
# ---------------------------------------------------------------------------


class PickAndPlace(Node):
    def __init__(self):
        super().__init__('pick_and_place')

        self.move_client = ActionClient(self, MoveGripper, '/move_gripper')
        self.gripper_client = ActionClient(
            self, GripperCommand, '/gripper_action_controller/gripper_cmd'
        )

        self.get_logger().info('Waiting for action servers...')
        if not self.move_client.wait_for_server(timeout_sec=SERVER_WAIT_TIMEOUT_SEC):
            raise RuntimeError('/move_gripper action server not available')
        if not self.gripper_client.wait_for_server(timeout_sec=SERVER_WAIT_TIMEOUT_SEC):
            raise RuntimeError(
                '/gripper_action_controller/gripper_cmd action server not available'
            )
        self.get_logger().info('Action servers ready.')

    # --- Helpers ----------------------------------------------------------
    def _send_and_wait(self, client, goal_msg):
        """Send a goal and block until the result is returned. Returns the result or None."""
        send_future = client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, send_future)
        goal_handle = send_future.result()

        if goal_handle is None or not goal_handle.accepted:
            self.get_logger().warn('Goal was rejected by the server.')
            return None

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        wrapped = result_future.result()
        return wrapped.result if wrapped is not None else None

    def _move_succeeded(self, result) -> bool:
        """Treat a result as successful if it exists. If the MoveGripper result
        message has a `success` field, honor it; otherwise assume success on completion."""
        if result is None:
            return False
        if hasattr(result, 'success'):
            return bool(result.success)
        return True

    # --- Actions ----------------------------------------------------------
    def move_gripper_to(self, x, y, z, use_default_z=False, label='') -> bool:
        """Send a /move_gripper goal with retries. Returns True on success."""
        for attempt in range(1, MAX_RETRIES + 1):
            self.get_logger().info(
                f'[{label}] Move attempt {attempt}/{MAX_RETRIES} -> '
                f'(x={x}, y={y}, z={z}, use_default_z={use_default_z})'
            )
            goal = MoveGripper.Goal()
            goal.x = float(x)
            goal.y = float(y)
            goal.z = float(z)
            goal.use_default_z = bool(use_default_z)

            result = self._send_and_wait(self.move_client, goal)
            if self._move_succeeded(result):
                msg = getattr(result, 'message', '')
                self.get_logger().info(
                    f'[{label}] Move succeeded.' + (f' ({msg})' if msg else '')
                )
                return True

            reason = getattr(result, 'message', '') if result is not None else 'no result / rejected'
            self.get_logger().warn(
                f'[{label}] Move failed on attempt {attempt}: {reason or "unknown"}'
            )
            if attempt < MAX_RETRIES:
                time.sleep(RETRY_DELAY_SEC)

        self.get_logger().error(f'[{label}] Move failed after {MAX_RETRIES} attempts.')
        return False

    def command_gripper(self, position, max_effort=0.0, label='') -> bool:
        """Send a GripperCommand goal. No retry — gripper commands are usually idempotent."""
        self.get_logger().info(
            f'[{label}] Gripper -> position={position}, max_effort={max_effort}'
        )
        goal = GripperCommand.Goal()
        goal.command.position = float(position)
        goal.command.max_effort = float(max_effort)

        result = self._send_and_wait(self.gripper_client, goal)
        if result is None:
            self.get_logger().error(f'[{label}] Gripper command failed.')
            return False
        self.get_logger().info(f'[{label}] Gripper command complete.')
        return True

    # --- Top-level sequence ----------------------------------------------
    def run(self) -> bool:
        steps = [
            ('1. Above object',
             lambda: self.move_gripper_to(*ABOVE_OBJECT, label='above')),
            ('2. Grasp position',
             lambda: self.move_gripper_to(*GRASP_POSE, label='grasp')),
            ('3. Close gripper',
             lambda: self.command_gripper(GRIPPER_CLOSED, 0.0, label='close')),
            ('4. Above object',
             lambda: self.move_gripper_to(*ABOVE_OBJECT, label='above')),
            ('5. Dropoff location',
             lambda: self.move_gripper_to(*DROPOFF_POSE, label='dropoff')),
            ('6. Open gripper',
             lambda: self.command_gripper(GRIPPER_OPEN, 0.0, label='open')),
            ('7. Move to safe pose',
             lambda: self.move_gripper_to(*SAFE_POSE, label='safe')),
        ]

        for name, step in steps:
            self.get_logger().info(f'=== {name} ===')
            if not step():
                self.get_logger().error(
                    f'Step failed: {name}. Attempting to move to safe pose {SAFE_POSE}.'
                )
                # Try once to reach the safe pose; don't retry here to avoid
                # getting stuck in a fallback loop if the arm is in a bad state.
                safe_goal = MoveGripper.Goal()
                safe_goal.x, safe_goal.y, safe_goal.z = (float(v) for v in SAFE_POSE)
                safe_goal.use_default_z = False
                safe_result = self._send_and_wait(self.move_client, safe_goal)
                if self._move_succeeded(safe_result):
                    self.get_logger().info('Reached safe pose.')
                else:
                    reason = getattr(safe_result, 'message', '') if safe_result is not None else 'no result / rejected'
                    self.get_logger().error(f'Safe pose move also failed: {reason or "unknown"}')
                return False

        self.get_logger().info('Pick-and-place sequence completed successfully.')
        return True


def main(args=None):
    rclpy.init(args=args)
    node = None
    try:
        node = PickAndPlace()
        success = node.run()
        sys.exit(0 if success else 1)
    except KeyboardInterrupt:
        pass
    except Exception as e:
        if node is not None:
            node.get_logger().error(f'Unhandled exception: {e}')
        else:
            print(f'Unhandled exception during init: {e}', file=sys.stderr)
        sys.exit(1)
    finally:
        if node is not None:
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()