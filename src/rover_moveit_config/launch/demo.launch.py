import os
from moveit_configs_utils import MoveItConfigsBuilder
from moveit_configs_utils.launches import generate_demo_launch


def generate_launch_description():
    # Force the OS environment variable to true to disable Gazebo hardware
    os.environ['USE_MOCK_HARDWARE'] = 'true'

    moveit_config = (
        MoveItConfigsBuilder("duck_catcher_rover", package_name="rover_moveit_config")
        .to_moveit_configs()
    )
    
    return generate_demo_launch(moveit_config)
