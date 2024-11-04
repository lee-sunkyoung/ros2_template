#ifndef ROS2_DEMO__ROS2_DEMO_HPP_
#define ROS2_DEMO__ROS2_DEMO_HPP_

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "custom_msgs/srv/custom_srv.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace ros2_demo { 
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

class server : public rclcpp::Node
{
public:
    server();

private:
    void service_request(const std::shared_ptr<custom_msgs::srv::CustomSrv::Request> request,
    std::shared_ptr<custom_msgs::srv::CustomSrv::Response> response);

    rclcpp::Service<custom_msgs::srv::CustomSrv>::SharedPtr service_;
};

class client : public rclcpp::Node
{
public:
    client();
    void send_request(int64_t a, int64_t b);

private:
    void handle_response(rclcpp::Client<custom_msgs::srv::CustomSrv>::SharedFuture future);

    rclcpp::Client<custom_msgs::srv::CustomSrv>::SharedPtr client_; //클래스 이름이랑 변수 이름 구분이 필요해서
};

} //end ros2_demo namespace 

#endif // ROS2_DEMO__ROS2_DEMO_HPP_
