#pragma once

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <geometry_msgs/msg/twist.hpp>

namespace operation
{
    class JoyController : public rclcpp::Node
    {
        public:
            JoyController();
            ~JoyController();
            void joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg);
        private:
            rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub_joy_;
            rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_cmd_vel_;
            geometry_msgs::msg::Twist cmd_vel_;

            // joy stick axes to be loaded from yaml file
            int joy_top_left_button_idx;
            int joy_top_right_button_idx;
            int joy_left_stick_x_idx;
            int joy_left_stick_y_idx;
            int joy_right_stick_x_idx;
            int joy_right_stick_y_idx;

            // max command values to be loaded from yaml file
            float abs_max_linear_vel_x;
            float abs_max_linear_vel_y;
            float abs_max_angular_vel_z;
    };
}