#include "../include/ros2_demo/ClientServer.hpp"

namespace ClientServer {

////////////////////////////////////////
// server
////////////////////////////////////////

server::server() : Node("server_node") {
  service_ = this->create_service<custom_msgs::srv::CustomSrv>(
      "add_two_ints", std::bind(&server::service_request, this,
                                std::placeholders::_1, std::placeholders::_2));
}

void server::service_request(
    const std::shared_ptr<custom_msgs::srv::CustomSrv::Request> request,
    std::shared_ptr<custom_msgs::srv::CustomSrv::Response> response) {
  response->sum = request->a + request->b;
}

////////////////////////////////////////
// client
////////////////////////////////////////

client::client() : Node("client_node") {
  client_ = this->create_client<custom_msgs::srv::CustomSrv>("add_two_ints");
}; // client

void client::send_request(int64_t a, int64_t b) {
  auto request = std::make_shared<custom_msgs::srv::CustomSrv::Request>();
  request->a = a;
  request->b = b;

  while (!client_->wait_for_service(std::chrono::seconds(1))) {
    RCLCPP_WARN(this->get_logger(), "Waiting for service to be available...");
  }

  auto result = client_->async_send_request(
      request,
      std::bind(&client::handle_response, this, std::placeholders::_1));
}

void client::handle_response(
    rclcpp::Client<custom_msgs::srv::CustomSrv>::SharedFuture future) {
  auto response = future.get();
  RCLCPP_INFO(this->get_logger(), "Result of add_two_ints: %ld", response->sum);
}

} // end namespace ros2_demo
