# ros2_template
ros2_template (full version)

## Overview
The `ros2_template` package is a simple, but almost fully using ros2 functions for more structrual,readable code. 
This package allow users to write down their own package more faster,and easy way.
You may just extract part of it, or modify and proceed your development.

## Development Environment
| **OS** Ubuntu 22.04 |

| **ROS** Humble |

## Packages
 **this package has these sources.**
 
- simple publisher, subscriber node
- simple server, client node
- launch file
- parameters
- namespace
- multithreading



**for better development environment.
**
- seperated hpp, cpp, main code.
- launch file in two ways(py, yaml).
- made CmakeLists more easier to edit.
- added custom_msgs connections.

## Clone & Build
```shell
 cd ~/${YOUR_WORKSPACE}/src
 git clone https://github.com/lee-sunkyoung/ros2_template.git
 cd ..
 colcon_build
```
## Setup
```shell
 cd ~/${YOUR_WORKSPACE}/src
 git clone https://github.com/lee-sunkyoung/ros2_template.git
 cd ..
 colcon_build
```

```shell
source /opt/ros/humble/setup.bash && source install/setup.bash
```

## Usage 
- launch `ros2_template`
```shell
 ros2 launch ros2_template ros2_demo.launch.py
```

- run `ros2_template`
```shell
 ros2 run ros2_template ros2_demo
```
