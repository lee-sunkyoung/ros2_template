#include "../include/ros2_demo/pubsub.hpp"

namespace PubSub {

////////////////////////////////////////
// pubsub
////////////////////////////////////////

pubsub::pubsub() : Node("pubsub_node"), initial_value_(0) {
  init();

  // parameter setting & load from launch file
  this->declare_parameter<int64_t>("initial_value", 0);
  this->get_parameter("initial_value", initial_value_);
}

void pubsub::init() {
  //timer binding
  timer_ =
      this->create_wall_timer(500ms, std::bind(&pubsub::timer_callback, this));
  // publisher
  publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

  // subscribe
  subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&pubsub::topic_callback, this, _1));
}

// publisher
void pubsub::timer_callback() {
  auto message = std_msgs::msg::String();
  message.data = "Hello, world! " + std::to_string(initial_value_);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  publisher_->publish(message);
}

// subscriber
void pubsub::topic_callback(const std_msgs::msg::String &msg) {
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
}

} // end namespace ros2_demo
