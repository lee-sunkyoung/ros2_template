#ifndef PUBSUB_HPP_
#define PUBSUB_HPP_

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "custom_msgs/srv/custom_srv.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace PubSub { 
class pubsub : public rclcpp::Node {
public:
  pubsub();

private:
  void init();
  void timer_callback();

  // node running
  rclcpp::TimerBase::SharedPtr timer_;
  
  // publisher
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  int64_t initial_value_;

  // subscriber
  void topic_callback(const std_msgs::msg::String &msg);
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

};

} //end ros2_demo namespace 

#endif // PUBSUB_HPP_
