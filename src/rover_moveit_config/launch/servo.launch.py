import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from moveit_configs_utils import MoveItConfigsBuilder

def generate_launch_description():
    # Load MoveIt kinematics and parameters
    moveit_config = (
        MoveItConfigsBuilder("duck_catcher_rover", package_name="rover_moveit_config")
        .to_moveit_configs()
    )

    # Load the Servo YAML configuration
    servo_yaml = os.path.join(
        get_package_share_directory('rover_moveit_config'),
        'config',
        'servo_config.yaml'
    )

    # Define the standalone Servo node
    servo_node = Node(
        package="moveit_servo",
        executable="servo_node",
        parameters=[
            servo_yaml,
            moveit_config.robot_description,
            moveit_config.robot_description_semantic,
            moveit_config.robot_description_kinematics,
        ],
        output="screen",
    )

    return LaunchDescription([servo_node])
