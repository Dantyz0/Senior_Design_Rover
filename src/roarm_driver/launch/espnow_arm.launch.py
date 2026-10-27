from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    serial_port = LaunchConfiguration('serial_port')
    baud_rate = LaunchConfiguration('baud_rate')
    send_home = LaunchConfiguration('send_home_on_start')

    return LaunchDescription([
        DeclareLaunchArgument('serial_port', default_value='/dev/ttyUSB0'),
        DeclareLaunchArgument('baud_rate', default_value='115200'),
        DeclareLaunchArgument('send_home_on_start', default_value='false'),

        Node(
            package='roarm_driver',
            executable='espnow_bridge',
            name='espnow_bridge',
            output='screen',
            parameters=[{
                'serial_port': serial_port,
                'baud_rate': baud_rate,
                'send_home_on_start': send_home,
                'boot_delay_sec': 2.0,
            }],
        ),
    ])
