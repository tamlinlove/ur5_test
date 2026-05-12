from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
# 1. Add this import
from launch_ros.parameter_descriptions import ParameterValue

def generate_launch_description():
    # ... keep your existing configurations ...
    
    # Add these specific UR configurations
    ur_type = "ur5" # Or use LaunchConfiguration if you want it dynamic
    
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution([FindPackageShare("ur5_test"), "urdf", "ur5_hand_e.urdf.xacro"]),
            " ",
            "name:=", ur_type,
            " ",
            "tf_prefix:=", LaunchConfiguration("tf_prefix"),
            " ",
            "joint_limit_params:=", PathJoinSubstitution([FindPackageShare("ur_description"), "config", ur_type, "joint_limits.yaml"]),
            " ",
            "kinematics_params:=", PathJoinSubstitution([FindPackageShare("ur_description"), "config", ur_type, "default_kinematics.yaml"]),
            " ",
            "physical_params:=", PathJoinSubstitution([FindPackageShare("ur_description"), "config", ur_type, "physical_parameters.yaml"]),
            " ",
            "visual_params:=", PathJoinSubstitution([FindPackageShare("ur_description"), "config", ur_type, "visual_parameters.yaml"]),
            " ",
            "safety_limits:=", "true",
            " ",
            "safety_pos_margin:=", "0.15",
            " ",
            "safety_k_position:=", "20",
        ]
    )

    tf_prefix = LaunchConfiguration("tf_prefix")
    ur_description_path = FindPackageShare("ur_description")

    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution([FindPackageShare("ur5_test"), "urdf", "ur5_hand_e.urdf.xacro"]),
            " ",
            "joint_limit_params:=", PathJoinSubstitution([ur_description_path, "config", "ur5", "joint_limits.yaml"]),
            " ",
            "kinematics_params:=", PathJoinSubstitution([ur_description_path, "config", "ur5", "default_kinematics.yaml"]),
            " ",
            "physical_params:=", PathJoinSubstitution([ur_description_path, "config", "ur5", "physical_parameters.yaml"]),
            " ",
            "visual_params:=", PathJoinSubstitution([ur_description_path, "config", "ur5", "visual_parameters.yaml"]),
            " ",
            "tf_prefix:=", tf_prefix,
        ]
    )

    robot_description = {
        "robot_description": ParameterValue(robot_description_content, value_type=str)
    }

    robot_state_publisher_node = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        output="both",
        parameters=[robot_description],
    )

    return LaunchDescription([
        DeclareLaunchArgument("description_package", default_value="ur5_test"),
        DeclareLaunchArgument("description_file", default_value="ur5_hand_e.urdf.xacro"),
        DeclareLaunchArgument("tf_prefix", default_value=""),
        robot_state_publisher_node,
    ])