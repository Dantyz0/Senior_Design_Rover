// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from roarm_msgs:srv/ServoCommandType.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roarm_msgs/srv/servo_command_type.hpp"


#ifndef ROARM_MSGS__SRV__DETAIL__SERVO_COMMAND_TYPE__BUILDER_HPP_
#define ROARM_MSGS__SRV__DETAIL__SERVO_COMMAND_TYPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "roarm_msgs/srv/detail/servo_command_type__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace roarm_msgs
{

namespace srv
{

namespace builder
{

class Init_ServoCommandType_Request_command_type
{
public:
  Init_ServoCommandType_Request_command_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::roarm_msgs::srv::ServoCommandType_Request command_type(::roarm_msgs::srv::ServoCommandType_Request::_command_type_type arg)
  {
    msg_.command_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_msgs::srv::ServoCommandType_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_msgs::srv::ServoCommandType_Request>()
{
  return roarm_msgs::srv::builder::Init_ServoCommandType_Request_command_type();
}

}  // namespace roarm_msgs


namespace roarm_msgs
{

namespace srv
{

namespace builder
{

class Init_ServoCommandType_Response_success
{
public:
  Init_ServoCommandType_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::roarm_msgs::srv::ServoCommandType_Response success(::roarm_msgs::srv::ServoCommandType_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_msgs::srv::ServoCommandType_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_msgs::srv::ServoCommandType_Response>()
{
  return roarm_msgs::srv::builder::Init_ServoCommandType_Response_success();
}

}  // namespace roarm_msgs


namespace roarm_msgs
{

namespace srv
{

namespace builder
{

class Init_ServoCommandType_Event_response
{
public:
  explicit Init_ServoCommandType_Event_response(::roarm_msgs::srv::ServoCommandType_Event & msg)
  : msg_(msg)
  {}
  ::roarm_msgs::srv::ServoCommandType_Event response(::roarm_msgs::srv::ServoCommandType_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::roarm_msgs::srv::ServoCommandType_Event msg_;
};

class Init_ServoCommandType_Event_request
{
public:
  explicit Init_ServoCommandType_Event_request(::roarm_msgs::srv::ServoCommandType_Event & msg)
  : msg_(msg)
  {}
  Init_ServoCommandType_Event_response request(::roarm_msgs::srv::ServoCommandType_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ServoCommandType_Event_response(msg_);
  }

private:
  ::roarm_msgs::srv::ServoCommandType_Event msg_;
};

class Init_ServoCommandType_Event_info
{
public:
  Init_ServoCommandType_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ServoCommandType_Event_request info(::roarm_msgs::srv::ServoCommandType_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ServoCommandType_Event_request(msg_);
  }

private:
  ::roarm_msgs::srv::ServoCommandType_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::roarm_msgs::srv::ServoCommandType_Event>()
{
  return roarm_msgs::srv::builder::Init_ServoCommandType_Event_info();
}

}  // namespace roarm_msgs

#endif  // ROARM_MSGS__SRV__DETAIL__SERVO_COMMAND_TYPE__BUILDER_HPP_
