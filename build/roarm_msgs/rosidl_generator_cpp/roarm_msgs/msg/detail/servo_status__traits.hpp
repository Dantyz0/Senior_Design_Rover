// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roarm_msgs:msg/ServoStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roarm_msgs/msg/servo_status.hpp"


#ifndef ROARM_MSGS__MSG__DETAIL__SERVO_STATUS__TRAITS_HPP_
#define ROARM_MSGS__MSG__DETAIL__SERVO_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "roarm_msgs/msg/detail/servo_status__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace roarm_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ServoStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: code
  {
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ServoStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "code: ";
    rosidl_generator_traits::value_to_yaml(msg.code, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ServoStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, roarm_msgs::msg::ServoStatus>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).code,
    std::forward<T>(msg).message);
}

}  // namespace msg

}  // namespace roarm_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<roarm_msgs::msg::ServoStatus>()
{
  return "roarm_msgs::msg::ServoStatus";
}

template<>
constexpr const char * name<roarm_msgs::msg::ServoStatus>()
{
  return "roarm_msgs/msg/ServoStatus";
}

template<>
struct has_fixed_size<roarm_msgs::msg::ServoStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roarm_msgs::msg::ServoStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roarm_msgs::msg::ServoStatus>
  : std::true_type {};

template<>
struct MessageTraits<roarm_msgs::msg::ServoStatus>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "code",
    "message",
  };
};

}  // namespace rosidl_generator_traits

#endif  // ROARM_MSGS__MSG__DETAIL__SERVO_STATUS__TRAITS_HPP_
