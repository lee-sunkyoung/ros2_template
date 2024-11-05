
#include "../include/ros2_demo/pubsub.hpp"
#include "../include/ros2_demo/ClientServer.hpp"


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto server_node = std::make_shared<ClientServer::server>();
  auto client_node = std::make_shared<ClientServer::client>();

  //multithreading -- u need this when ur not using launch file.
  rclcpp::executors::MultiThreadedExecutor executor(rclcpp::ExecutorOptions(), 2);
  executor.add_node(server_node);
  executor.add_node(client_node);

 client_node->send_request(3,7);

  executor.spin();

  rclcpp::shutdown();
  return 0;
}