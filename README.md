# ros2_template
ros2_template (full version)

## Overview
The ros2_template package provides a streamlined, structured foundation for creating ROS 2 packages efficiently, with readable code.
You may just extract part of it, or modify and proceed your development.

## Development Environment
| **OS** Ubuntu 22.04 |

| **ROS** Humble |

## Packages Description
 **sources**
 
 [pubsub]
- simple publisher, subscriber node
- parameters
- namespace

[ClientServer]
- simple server, client node
- multithreading
- namespace

[custom_msgs]
- simple srv file
- simple msg file

[launch]
- launch file

[CmakeLists.txt & package.xml]
- It was designed easy to edit or modify.


**for better development environment.**
- seperated hpp, cpp, main code.
- launch file in two ways(py, yaml).
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
 colcon build
```

```shell
source /opt/ros/humble/setup.bash && source install/setup.bash
```

## to run each node separately
- run `pubsub`
```shell
 ros2 run ros2_demo pubsbub
```

- run `ClientServer`
```shell
 ros2 run ros2_demo ClientServer
```

## to launch both files together
- launch `ros2_demo`
```shell
 ros2 launch ros2_demo ros2_demo.launch.py
```

