cmake_minimum_required(VERSION 3.8)
project(ros2_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(custom_msgs REQUIRED)

# Include directories
include_directories(
        include/
       ${rclcpp_INCLUDE_DIRS}
       ${sensor_msgs_INCLUDE_DIRS}
       ${std_msgs_INCLUDE_DIRS}
       ${custom_msgs_INCLUDE_DIRS}
)

# Declare the library 
add_library(${PROJECT_NAME}_lib
  src/ros2_demo_node.cpp
)

set(DEPENDENCIES
  "rclcpp"
  "std_msgs"
  "sensor_msgs"
  "custom_msgs"
)

target_link_libraries(${PROJECT_NAME}_lib)
ament_target_dependencies(${PROJECT_NAME}_lib ${DEPENDENCIES})

# Declare the executable
add_executable(ros2_demo src/ros2_demo.cpp src/ros2_demo_node.cpp)
target_link_libraries(ros2_demo ${PROJECT_NAME}_lib)
ament_target_dependencies(ros2_demo ${DEPENDENCIES})

# Install
install(TARGETS
  ros2_demo
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)


# Export include directories
ament_export_include_directories(include)

ament_package()
