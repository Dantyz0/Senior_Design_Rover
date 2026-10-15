// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roarm_msgs:srv/GetPoseCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roarm_msgs/srv/get_pose_cmd.hpp"


#ifndef ROARM_MSGS__SRV__DETAIL__GET_POSE_CMD__TRAITS_HPP_
#define ROARM_MSGS__SRV__DETAIL__GET_POSE_CMD__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "roarm_msgs/srv/detail/get_pose_cmd__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace roarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPoseCmd_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPoseCmd_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPoseCmd_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, roarm_msgs::srv::GetPoseCmd_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(std::forward<T>(msg).structure_needs_at_least_one_member);
}

}  // namespace srv

}  // namespace roarm_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<roarm_msgs::srv::GetPoseCmd_Request>()
{
  return "roarm_msgs::srv::GetPoseCmd_Request";
}

template<>
constexpr const char * name<roarm_msgs::srv::GetPoseCmd_Request>()
{
  return "roarm_msgs/srv/GetPoseCmd_Request";
}

template<>
struct has_fixed_size<roarm_msgs::srv::GetPoseCmd_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<roarm_msgs::srv::GetPoseCmd_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<roarm_msgs::srv::GetPoseCmd_Request>
  : std::true_type {};

template<>
struct MessageTraits<roarm_msgs::srv::GetPoseCmd_Request>
{
  static constexpr std::size_t member_count = 1;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "structure_needs_at_least_one_member",
  };
};

}  // namespace rosidl_generator_traits

namespace roarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPoseCmd_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPoseCmd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPoseCmd_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, roarm_msgs::srv::GetPoseCmd_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).x,
    std::forward<T>(msg).y,
    std::forward<T>(msg).z,
    std::forward<T>(msg).roll,
    std::forward<T>(msg).pitch,
    std::forward<T>(msg).yaw);
}

}  // namespace srv

}  // namespace roarm_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<roarm_msgs::srv::GetPoseCmd_Response>()
{
  return "roarm_msgs::srv::GetPoseCmd_Response";
}

template<>
constexpr const char * name<roarm_msgs::srv::GetPoseCmd_Response>()
{
  return "roarm_msgs/srv/GetPoseCmd_Response";
}

template<>
struct has_fixed_size<roarm_msgs::srv::GetPoseCmd_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<roarm_msgs::srv::GetPoseCmd_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<roarm_msgs::srv::GetPoseCmd_Response>
  : std::true_type {};

template<>
struct MessageTraits<roarm_msgs::srv::GetPoseCmd_Response>
{
  static constexpr std::size_t member_count = 6;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "x",
    "y",
    "z",
    "roll",
    "pitch",
    "yaw",
  };
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace roarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetPoseCmd_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetPoseCmd_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetPoseCmd_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, roarm_msgs::srv::GetPoseCmd_Event>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).info,
    std::forward<T>(msg).request,
    std::forward<T>(msg).response);
}

}  // namespace srv

}  // namespace roarm_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<roarm_msgs::srv::GetPoseCmd_Event>()
{
  return "roarm_msgs::srv::GetPoseCmd_Event";
}

template<>
constexpr const char * name<roarm_msgs::srv::GetPoseCmd_Event>()
{
  return "roarm_msgs/srv/GetPoseCmd_Event";
}

template<>
struct has_fixed_size<roarm_msgs::srv::GetPoseCmd_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roarm_msgs::srv::GetPoseCmd_Event>
  : std::integral_constant<bool, has_bounded_size<roarm_msgs::srv::GetPoseCmd_Request>::value && has_bounded_size<roarm_msgs::srv::GetPoseCmd_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<roarm_msgs::srv::GetPoseCmd_Event>
  : std::true_type {};

template<>
struct MessageTraits<roarm_msgs::srv::GetPoseCmd_Event>
{
  static constexpr std::size_t member_count = 3;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "info",
    "request",
    "response",
  };
};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<roarm_msgs::srv::GetPoseCmd>()
{
  return "roarm_msgs::srv::GetPoseCmd";
}

template<>
constexpr const char * name<roarm_msgs::srv::GetPoseCmd>()
{
  return "roarm_msgs/srv/GetPoseCmd";
}

template<>
struct has_fixed_size<roarm_msgs::srv::GetPoseCmd>
  : std::integral_constant<
    bool,
    has_fixed_size<roarm_msgs::srv::GetPoseCmd_Request>::value &&
    has_fixed_size<roarm_msgs::srv::GetPoseCmd_Response>::value
  >
{
};

template<>
struct has_bounded_size<roarm_msgs::srv::GetPoseCmd>
  : std::integral_constant<
    bool,
    has_bounded_size<roarm_msgs::srv::GetPoseCmd_Request>::value &&
    has_bounded_size<roarm_msgs::srv::GetPoseCmd_Response>::value
  >
{
};

template<>
struct is_service<roarm_msgs::srv::GetPoseCmd>
  : std::true_type
{
};

template<>
struct is_service_request<roarm_msgs::srv::GetPoseCmd_Request>
  : std::true_type
{
};

template<>
struct is_service_response<roarm_msgs::srv::GetPoseCmd_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROARM_MSGS__SRV__DETAIL__GET_POSE_CMD__TRAITS_HPP_
