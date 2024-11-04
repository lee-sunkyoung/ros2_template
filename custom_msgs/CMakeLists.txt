cmake_minimum_required(VERSION 3.8)
project(custom_msgs)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/CustomSrv.srv"
  "msg/CustomMsg.msg"
  DEPENDENCIES std_msgs
   # Add packages that above messages depend on, in this case geometry_msgs for Sphere.msg
)

ament_package()
