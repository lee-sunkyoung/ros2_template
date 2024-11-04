#include "../include/ros2_demo/ros2_demo.hpp"
//#include "../ros2_demo_node.cpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto pubsub_node = std::make_shared<ros2_demo::pubsub>();
  auto server_node = std::make_shared<ros2_demo::server>();
  auto client_node = std::make_shared<ros2_demo::client>();

  //multithreading -- this only needed when yr not using launch file.
  rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), 2);
  executor.add_node(pubsub_node);
  executor.add_node(server_node);
  executor.add_node(client_node);

 client_node->send_request(3,7);

  executor.spin();

  rclcpp::shutdown();
  return 0;
}