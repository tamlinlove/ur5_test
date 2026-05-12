#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer
from rclpy.action.server import ServerGoalHandle, GoalResponse, CancelResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.duration import Duration

from tf2_ros import Buffer, TransformListener, LookupException, ExtrapolationException

from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import (
    Constraints, JointConstraint, MoveItErrorCodes,
    PositionConstraint, BoundingVolume, OrientationConstraint,
    WorkspaceParameters,
)
from geometry_msgs.msg import Pose
from shape_msgs.msg import SolidPrimitive

from ur5_test.action import MoveGripper

# ---- Constants ----
TABLE_HEIGHT = 0.8
WRIST_LENGTH = 0.18
HEIGHT_ABOVE_TABLE = 0.4
DEFAULT_WRIST_HEIGHT = TABLE_HEIGHT + HEIGHT_ABOVE_TABLE - WRIST_LENGTH

PLANNING_TIME = 5
PLANNING_ATTEMPTS = 5

# Workspace bounds (in world frame, X/Y only; Z gets table height added)
X_MIN, X_MAX = -0.7, 0.7
Y_MIN, Y_MAX = 0.0, 1.0

# Planner selection
# If |dx| and |dy| are both below this, treat the motion as pure-Z and use LIN.
XY_EQUAL_TOL = 0.02  # metres

# Pipeline / planner IDs
OMPL_PIPELINE = "ompl"
OMPL_PLANNER = "RRTstarConfigDefault"
PILZ_PIPELINE = "pilz_industrial_motion_planner"
PILZ_LIN_PLANNER = "LIN"

# Frames / links
WORLD_FRAME = "world"
EEF_LINK = "tool0"
ELBOW_LINK = "forearm_link"  # link whose origin is at the elbow joint

# Elbow keep-out: the elbow link's origin must end up above this Z in the
# world frame, to keep it away from the table. Goal constraint only --
# not enforced along the path.
ELBOW_MIN_Z = 0.9
ELBOW_MAX_Z = 2.0  # ceiling for the bounding box


class GripperPositionerServer(Node):
    def __init__(self):
        super().__init__('gripper_positioner_server')

        self._cb_group = ReentrantCallbackGroup()

        # TF buffer for reading the current end-effector pose
        self._tf_buffer = Buffer()
        self._tf_listener = TransformListener(self._tf_buffer, self)

        # MoveGroup client
        self._move_group_client = ActionClient(
            self, MoveGroup, 'move_action',
            callback_group=self._cb_group,
        )
        self.get_logger().info("Waiting for move_group action server...")
        self._move_group_client.wait_for_server()
        self.get_logger().info("move_group is up.")

        # Our action server
        self._action_server = ActionServer(
            self,
            MoveGripper,
            'move_gripper',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            callback_group=self._cb_group,
        )
        self.get_logger().info("move_gripper action server ready.")

    # ---- Goal validation ----
    def goal_callback(self, goal_request):
        x, y = goal_request.x, goal_request.y
        if not (X_MIN <= x <= X_MAX):
            self.get_logger().warn(
                f"Rejecting goal: x={x:.3f} outside [{X_MIN}, {X_MAX}]"
            )
            return GoalResponse.REJECT
        if not (Y_MIN <= y <= Y_MAX):
            self.get_logger().warn(
                f"Rejecting goal: y={y:.3f} outside [{Y_MIN}, {Y_MAX}]"
            )
            return GoalResponse.REJECT
        self.get_logger().info(f"Accepting goal: x={x:.3f}, y={y:.3f}")
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle):
        self.get_logger().info("Cancel requested.")
        return CancelResponse.ACCEPT

    # ---- Helpers ----
    def _get_current_eef_xyz(self):
        """Return (x, y, z) of tool0 in world frame, or None on failure."""
        try:
            tf = self._tf_buffer.lookup_transform(
                WORLD_FRAME, EEF_LINK,
                rclpy.time.Time(),
                timeout=Duration(seconds=1.0),
            )
        except (LookupException, ExtrapolationException) as e:
            self.get_logger().warn(f"TF lookup {WORLD_FRAME}->{EEF_LINK} failed: {e}")
            return None
        t = tf.transform.translation
        return (t.x, t.y, t.z)

    def _select_planner(self, target_x, target_y):
        """
        Decide which (pipeline, planner) to use.
        Pure-Z motion -> Pilz LIN; otherwise OMPL RRT*.
        Falls back to OMPL if the current EEF pose can't be read.
        """
        current = self._get_current_eef_xyz()
        if current is None:
            self.get_logger().info("No current pose available; defaulting to OMPL.")
            return OMPL_PIPELINE, OMPL_PLANNER, False

        cx, cy, _ = current
        dx, dy = abs(target_x - cx), abs(target_y - cy)
        if dx < XY_EQUAL_TOL and dy < XY_EQUAL_TOL:
            self.get_logger().info(
                f"Pure-Z motion detected (|dx|={dx:.4f}, |dy|={dy:.4f}); using Pilz LIN."
            )
            return PILZ_PIPELINE, PILZ_LIN_PLANNER, True

        self.get_logger().info(
            f"current=({cx:.4f},{cy:.4f}) target=({target_x:.4f},{target_y:.4f}) "
            f"|dx|={dx:.4f} |dy|={dy:.4f} tol={XY_EQUAL_TOL}"
        )

        self.get_logger().info(
            f"General motion (|dx|={dx:.4f}, |dy|={dy:.4f}); using OMPL."
        )
        return OMPL_PIPELINE, OMPL_PLANNER, False

    # ---- Main execution ----
    async def execute_callback(self, goal_handle: ServerGoalHandle):
        req = goal_handle.request

        # Resolve Z
        if req.use_default_z:
            target_z = DEFAULT_WRIST_HEIGHT
        else:
            target_z = req.z + TABLE_HEIGHT - WRIST_LENGTH

        target_x, target_y = req.x, req.y

        # Choose the planner based on the current vs. target pose
        pipeline_id, planner_id, is_linear = self._select_planner(target_x, target_y)

        fb = MoveGripper.Feedback()
        fb.status = (
            f"Planning to ({target_x:.3f}, {target_y:.3f}, {target_z:.3f}) "
            f"with {pipeline_id}/{planner_id}"
        )
        goal_handle.publish_feedback(fb)

        mg_goal = self._build_move_group_goal(
            target_x, target_y, target_z,
            pipeline_id=pipeline_id,
            planner_id=planner_id,
            is_linear=is_linear,
        )

        send_future = self._move_group_client.send_goal_async(mg_goal)
        mg_handle = await send_future

        if not mg_handle.accepted:
            goal_handle.abort()
            result = MoveGripper.Result()
            result.success = False
            result.message = "MoveGroup rejected the goal."
            self.get_logger().error(result.message)
            return result

        fb.status = "MoveGroup accepted. Executing trajectory..."
        goal_handle.publish_feedback(fb)

        mg_result = await mg_handle.get_result_async()
        error_code = mg_result.result.error_code.val

        result = MoveGripper.Result()
        if error_code == MoveItErrorCodes.SUCCESS:
            goal_handle.succeed()
            result.success = True
            result.message = "Wrist in position."
            self.get_logger().info(result.message)
        else:
            goal_handle.abort()
            result.success = False
            result.message = (
                f"MoveIt failed with error code {error_code} "
                f"(planner: {pipeline_id}/{planner_id})."
            )
            self.get_logger().error(result.message)

        return result

    # ---- Goal construction ----
    def _build_move_group_goal(
        self, target_x, target_y, target_z,
        pipeline_id=OMPL_PIPELINE,
        planner_id=OMPL_PLANNER,
        is_linear=False,
    ):
        goal_msg = MoveGroup.Goal()
        goal_msg.request.group_name = "ur_manipulator"
        goal_msg.request.pipeline_id = pipeline_id
        goal_msg.request.planner_id = planner_id
        goal_msg.request.allowed_planning_time = float(PLANNING_TIME)
        goal_msg.request.num_planning_attempts = 1 if is_linear else int(PLANNING_ATTEMPTS)
        goal_msg.request.max_velocity_scaling_factor = 0.6
        goal_msg.request.max_acceleration_scaling_factor = 0.1

        # Planning volume hint for OMPL sampling.
        # Note: this is *not* a collision boundary -- it only bounds where
        # OMPL samples states. Collision obstacles (table, workspace_obstacle,
        # standing_area, ceiling) come from the URDF/SRDF. Setting this also
        # suppresses the "planning volume was not specified" warning.
        ws = WorkspaceParameters()
        ws.header.frame_id = WORLD_FRAME
        ws.min_corner.x = -0.8
        ws.min_corner.y = -0.3
        ws.min_corner.z = 0.7
        ws.max_corner.x = 0.8
        ws.max_corner.y = 1.0
        ws.max_corner.z = 1.8
        goal_msg.request.workspace_parameters = ws

        # Position constraint on tool0.
        # Pilz LIN expects a tight Cartesian goal; OMPL is fine with the
        # 2 cm sphere your original used.
        pos_con = PositionConstraint()
        pos_con.header.frame_id = WORLD_FRAME
        pos_con.link_name = EEF_LINK

        target_p = Pose()
        target_p.position.x = target_x
        target_p.position.y = target_y
        target_p.position.z = target_z
        # LIN also wants a sensible orientation in the goal pose itself
        target_p.orientation.x = 1.0
        target_p.orientation.y = 0.0
        target_p.orientation.z = 0.0
        target_p.orientation.w = 0.0

        s = SolidPrimitive()
        s.type = SolidPrimitive.SPHERE
        s.dimensions = [0.001 if is_linear else 0.02]

        bv = BoundingVolume()
        bv.primitives.append(s)
        bv.primitive_poses.append(target_p)
        pos_con.constraint_region = bv
        pos_con.weight = 1.0

        # Orientation: pointing down
        oc = OrientationConstraint()
        oc.header.frame_id = WORLD_FRAME
        oc.link_name = EEF_LINK
        oc.orientation.x = 1.0
        oc.orientation.y = 0.0
        oc.orientation.z = 0.0
        oc.orientation.w = 0.0
        oc.absolute_x_axis_tolerance = 0.05
        oc.absolute_y_axis_tolerance = 0.05
        oc.absolute_z_axis_tolerance = math.pi
        oc.weight = 1.0

        goal_constraints = Constraints()
        goal_constraints.position_constraints.append(pos_con)
        goal_constraints.orientation_constraints.append(oc)

        # Elbow-up goal constraint.
        #
        # A pure Cartesian "elbow above wrist in world Z" condition turns out
        # to be geometrically infeasible for this setup: with the UR5 base at
        # ~0.8 m and the upper-arm length ~0.425 m, the elbow's maximum world
        # Z is around 1.32 m, while the wrist link sits at target_z + 0.18 m,
        # which at typical pick heights is already at or above that ceiling.
        #
        # The elbow-up JointConstraint achieves the practical intent (forearm
        # comes *down* from elbow to wrist at an angle that keeps it out of
        # the workspace beneath the gripper) and is what the original code
        # used. We apply it as a GOAL constraint only -- not a path
        # constraint -- so the current start state is never rejected before
        # planning begins, and the IK sampler can use it directly to bias
        # toward the elbow-up branch.
        #
        # Skipped for Pilz LIN: it does a straight Cartesian line that won't
        # flip the elbow branch, and it ignores arbitrary extra constraints
        # anyway.
        if not is_linear:
            elbow_up_jc = JointConstraint()
            elbow_up_jc.joint_name = "elbow_joint"
            elbow_up_jc.position = -1.57
            elbow_up_jc.tolerance_above = 1.57
            elbow_up_jc.tolerance_below = 1.57
            elbow_up_jc.weight = 1.0
            goal_constraints.joint_constraints.append(elbow_up_jc)

            # Elbow height keep-out (goal-only).
            #
            # Keep the elbow link's origin above ELBOW_MIN_Z in the world
            # frame so it doesn't end up close to the table at the final
            # pose. Modelled as a tall box from ELBOW_MIN_Z up to
            # ELBOW_MAX_Z, spanning a generous X/Y envelope around the
            # workspace -- MoveIt requires a closed bounding volume, so we
            # can't express "Z >= 0.9" as a half-space directly.
            #
            # This complements the elbow_joint JointConstraint above:
            # the joint constraint biases toward the elbow-up IK branch;
            # the position constraint additionally rules out final poses
            # where, despite being on the elbow-up branch, the elbow has
            # ended up dipping low in the world frame.
            elbow_pos_con = PositionConstraint()
            elbow_pos_con.header.frame_id = WORLD_FRAME
            elbow_pos_con.link_name = ELBOW_LINK

            box_x_size = 3.0
            box_y_size = 3.0
            box_z_size = ELBOW_MAX_Z - ELBOW_MIN_Z

            elbow_box = SolidPrimitive()
            elbow_box.type = SolidPrimitive.BOX
            elbow_box.dimensions = [box_x_size, box_y_size, box_z_size]

            elbow_box_pose = Pose()
            elbow_box_pose.position.x = 0.0
            elbow_box_pose.position.y = 0.0
            elbow_box_pose.position.z = ELBOW_MIN_Z + box_z_size / 2.0
            elbow_box_pose.orientation.w = 1.0

            elbow_bv = BoundingVolume()
            elbow_bv.primitives.append(elbow_box)
            elbow_bv.primitive_poses.append(elbow_box_pose)
            elbow_pos_con.constraint_region = elbow_bv
            elbow_pos_con.weight = 1.0

            goal_constraints.position_constraints.append(elbow_pos_con)

        goal_msg.request.goal_constraints.append(goal_constraints)
        return goal_msg


def main():
    rclpy.init()
    node = GripperPositionerServer()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()