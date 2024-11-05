
#include "../include/ros2_demo/pubsub.hpp"
#include "../include/ros2_demo/ClientServer.hpp"


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto pubsub_node = std::make_shared<PubSub::pubsub>();

  rclcpp::spin(pubsub_node);
  
  rclcpp::shutdown();
  return 0;
}

