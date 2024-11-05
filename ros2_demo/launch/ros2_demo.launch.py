# ros2_demo.launch.py
# this provides more specific expressions than .yaml model. 
 
import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ros2_demo',
            executable='pubsub',
            name='pubsub_node',
            output='screen',
            parameters=[{'initial_value': 10}],
        ),
        Node(
            package='ros2_demo',
            executable='ClientServer',
            name='client_node',
            output='screen',
        )
    ])
