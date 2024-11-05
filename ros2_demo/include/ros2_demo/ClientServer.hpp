#ifndef CLIENT_SERVER_HPP_
#define CLIENT_SERVER_HPP_

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "custom_msgs/srv/custom_srv.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

namespace ClientServer { 
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

#endif // CLIENT_SERVER_HPP_
