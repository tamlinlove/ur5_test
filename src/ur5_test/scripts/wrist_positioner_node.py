#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from rclpy.action import ActionClient
from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import Constraints, JointConstraint, MoveItErrorCodes, PositionConstraint, BoundingVolume
from geometry_msgs.msg import Pose, PoseStamped
from shape_msgs.msg import SolidPrimitive
from moveit_msgs.msg import OrientationConstraint
from geometry_msgs.msg import Quaternion

TABLE_HEIGHT = 0.8
WRIST_LENGTH = 0.18
HEIGHT_ABOVE_TABLE = 0.4
DEFAULT_WRIST_HEIGHT = TABLE_HEIGHT + HEIGHT_ABOVE_TABLE - WRIST_LENGTH

class WristPositioner(Node):
    def __init__(self):
        super().__init__('wrist_positioner_node')
        
        self._action_client = ActionClient(self, MoveGroup, 'move_action')
        self.get_logger().info("Waiting for move_group action server...")
        self._action_client.wait_for_server()

    def move_wrist_to_coords(self, target_x, target_y):
        goal_msg = MoveGroup.Goal()
        goal_msg.request.group_name = "ur_manipulator"
        
        # ---- Planner selection: asymptotically optimal ----
        #goal_msg.request.planner_id = "RRTstarkConfigDefault"
        goal_msg.request.allowed_planning_time = 5.0      # RRTstar improves with time
        goal_msg.request.num_planning_attempts = 5        # take best of N
        
        # Speed and Acceleration Control
        goal_msg.request.max_velocity_scaling_factor = 0.4
        goal_msg.request.max_acceleration_scaling_factor = 0.05

        # ---- Goal: position of tool0 ----
        pos_con = PositionConstraint()
        pos_con.header.frame_id = "world"
        pos_con.link_name = "tool0"
        
        target_p = Pose()
        target_p.position.x = target_x
        target_p.position.y = target_y
        target_p.position.z = DEFAULT_WRIST_HEIGHT

        s = SolidPrimitive()
        s.type = SolidPrimitive.SPHERE
        s.dimensions = [0.02]
        
        bv = BoundingVolume()
        bv.primitives.append(s)
        bv.primitive_poses.append(target_p)
        
        pos_con.constraint_region = bv
        pos_con.weight = 1.0

        # ---- Goal: orientation of tool0 (pointing down) ----
        oc = OrientationConstraint()
        oc.header.frame_id = "world"
        oc.link_name = "tool0"
        oc.orientation.x = 1.0
        oc.orientation.y = 0.0
        oc.orientation.z = 0.0
        oc.orientation.w = 0.0
        oc.absolute_x_axis_tolerance = 0.05
        oc.absolute_y_axis_tolerance = 0.05
        oc.absolute_z_axis_tolerance = math.pi
        oc.weight = 1.0

        # ---- Elbow joint constraint (used as BOTH goal and path constraint) ----
        elbow_con = JointConstraint()
        elbow_con.joint_name = "elbow_joint"
        elbow_con.position = -1.57
        elbow_con.tolerance_above = 1.57
        elbow_con.tolerance_below = 1.57
        elbow_con.weight = 1.0

        # Goal constraints
        goal_constraints = Constraints()
        goal_constraints.position_constraints.append(pos_con)
        goal_constraints.orientation_constraints.append(oc)
        goal_constraints.joint_constraints.append(elbow_con)
        goal_msg.request.goal_constraints.append(goal_constraints)

        # ---- Path constraints: hold elbow-up THROUGHOUT trajectory ----
        path_constraints = Constraints()
        path_constraints.joint_constraints.append(elbow_con)
        goal_msg.request.path_constraints = path_constraints

        self.get_logger().info(
            f"Planning (RRTstar, 5s, 5 attempts): tool0 -> ({target_x}, {target_y}, {DEFAULT_WRIST_HEIGHT:.2f}) "
            "with vertical orientation and elbow-up throughout."
        )
        
        send_goal_future = self._action_client.send_goal_async(goal_msg)
        send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error("Goal rejected by MoveGroup")
            return
        self.get_logger().info("Goal accepted. Moving...")
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        if result.error_code.val == MoveItErrorCodes.SUCCESS:
            self.get_logger().info("Success! Wrist is in position.")
        else:
            self.get_logger().error(f"Failed with code: {result.error_code.val}")

def main():
    rclpy.init()
    node = WristPositioner()
    node.move_wrist_to_coords(0.0, 0.3)
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()