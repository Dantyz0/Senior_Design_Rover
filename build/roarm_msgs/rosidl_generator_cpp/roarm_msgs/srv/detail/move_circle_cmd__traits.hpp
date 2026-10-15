// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from roarm_msgs:srv/MoveCircleCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roarm_msgs/srv/move_circle_cmd.hpp"


#ifndef ROARM_MSGS__SRV__DETAIL__MOVE_CIRCLE_CMD__TRAITS_HPP_
#define ROARM_MSGS__SRV__DETAIL__MOVE_CIRCLE_CMD__TRAITS_HPP_

#include <stdint.h>

#include <array>
#include <cstddef>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

#include "roarm_msgs/srv/detail/move_circle_cmd__struct.hpp"
#include "rosidl_runtime_cpp/buffer__traits.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace roarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveCircleCmd_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x0
  {
    out << "x0: ";
    rosidl_generator_traits::value_to_yaml(msg.x0, out);
    out << ", ";
  }

  // member: y0
  {
    out << "y0: ";
    rosidl_generator_traits::value_to_yaml(msg.y0, out);
    out << ", ";
  }

  // member: z0
  {
    out << "z0: ";
    rosidl_generator_traits::value_to_yaml(msg.z0, out);
    out << ", ";
  }

  // member: x1
  {
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << ", ";
  }

  // member: y1
  {
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << ", ";
  }

  // member: z1
  {
    out << "z1: ";
    rosidl_generator_traits::value_to_yaml(msg.z1, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveCircleCmd_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x0: ";
    rosidl_generator_traits::value_to_yaml(msg.x0, out);
    out << "\n";
  }

  // member: y0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y0: ";
    rosidl_generator_traits::value_to_yaml(msg.y0, out);
    out << "\n";
  }

  // member: z0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z0: ";
    rosidl_generator_traits::value_to_yaml(msg.z0, out);
    out << "\n";
  }

  // member: x1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x1: ";
    rosidl_generator_traits::value_to_yaml(msg.x1, out);
    out << "\n";
  }

  // member: y1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y1: ";
    rosidl_generator_traits::value_to_yaml(msg.y1, out);
    out << "\n";
  }

  // member: z1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z1: ";
    rosidl_generator_traits::value_to_yaml(msg.z1, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveCircleCmd_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, roarm_msgs::srv::MoveCircleCmd_Request>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).x0,
    std::forward<T>(msg).y0,
    std::forward<T>(msg).z0,
    std::forward<T>(msg).x1,
    std::forward<T>(msg).y1,
    std::forward<T>(msg).z1);
}

}  // namespace srv

}  // namespace roarm_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<roarm_msgs::srv::MoveCircleCmd_Request>()
{
  return "roarm_msgs::srv::MoveCircleCmd_Request";
}

template<>
constexpr const char * name<roarm_msgs::srv::MoveCircleCmd_Request>()
{
  return "roarm_msgs/srv/MoveCircleCmd_Request";
}

template<>
struct has_fixed_size<roarm_msgs::srv::MoveCircleCmd_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<roarm_msgs::srv::MoveCircleCmd_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<roarm_msgs::srv::MoveCircleCmd_Request>
  : std::true_type {};

template<>
struct MessageTraits<roarm_msgs::srv::MoveCircleCmd_Request>
{
  static constexpr std::size_t member_count = 6;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "x0",
    "y0",
    "z0",
    "x1",
    "y1",
    "z1",
  };
};

}  // namespace rosidl_generator_traits

namespace roarm_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveCircleCmd_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
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
  const MoveCircleCmd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
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

inline std::string to_yaml(const MoveCircleCmd_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, roarm_msgs::srv::MoveCircleCmd_Response>, int> = 0>
constexpr auto as_tuple_ref(T && msg)
{
  return std::forward_as_tuple(
    std::forward<T>(msg).success,
    std::forward<T>(msg).message);
}

}  // namespace srv

}  // namespace roarm_msgs

namespace rosidl_generator_traits
{

template<>
constexpr const char * data_type<roarm_msgs::srv::MoveCircleCmd_Response>()
{
  return "roarm_msgs::srv::MoveCircleCmd_Response";
}

template<>
constexpr const char * name<roarm_msgs::srv::MoveCircleCmd_Response>()
{
  return "roarm_msgs/srv/MoveCircleCmd_Response";
}

template<>
struct has_fixed_size<roarm_msgs::srv::MoveCircleCmd_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roarm_msgs::srv::MoveCircleCmd_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<roarm_msgs::srv::MoveCircleCmd_Response>
  : std::true_type {};

template<>
struct MessageTraits<roarm_msgs::srv::MoveCircleCmd_Response>
{
  static constexpr std::size_t member_count = 2;
  static constexpr std::array<std::string_view, member_count> member_names = {
    "success",
    "message",
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
  const MoveCircleCmd_Event & msg,
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
  const MoveCircleCmd_Event & msg,
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

inline std::string to_yaml(const MoveCircleCmd_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

template<typename T, std::enable_if_t<std::is_same_v<std::decay_t<T>, roarm_msgs::srv::MoveCircleCmd_Event>, int> = 0>
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
constexpr const char * data_type<roarm_msgs::srv::MoveCircleCmd_Event>()
{
  return "roarm_msgs::srv::MoveCircleCmd_Event";
}

template<>
constexpr const char * name<roarm_msgs::srv::MoveCircleCmd_Event>()
{
  return "roarm_msgs/srv/MoveCircleCmd_Event";
}

template<>
struct has_fixed_size<roarm_msgs::srv::MoveCircleCmd_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<roarm_msgs::srv::MoveCircleCmd_Event>
  : std::integral_constant<bool, has_bounded_size<roarm_msgs::srv::MoveCircleCmd_Request>::value && has_bounded_size<roarm_msgs::srv::MoveCircleCmd_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<roarm_msgs::srv::MoveCircleCmd_Event>
  : std::true_type {};

template<>
struct MessageTraits<roarm_msgs::srv::MoveCircleCmd_Event>
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
constexpr const char * data_type<roarm_msgs::srv::MoveCircleCmd>()
{
  return "roarm_msgs::srv::MoveCircleCmd";
}

template<>
constexpr const char * name<roarm_msgs::srv::MoveCircleCmd>()
{
  return "roarm_msgs/srv/MoveCircleCmd";
}

template<>
struct has_fixed_size<roarm_msgs::srv::MoveCircleCmd>
  : std::integral_constant<
    bool,
    has_fixed_size<roarm_msgs::srv::MoveCircleCmd_Request>::value &&
    has_fixed_size<roarm_msgs::srv::MoveCircleCmd_Response>::value
  >
{
};

template<>
struct has_bounded_size<roarm_msgs::srv::MoveCircleCmd>
  : std::integral_constant<
    bool,
    has_bounded_size<roarm_msgs::srv::MoveCircleCmd_Request>::value &&
    has_bounded_size<roarm_msgs::srv::MoveCircleCmd_Response>::value
  >
{
};

template<>
struct is_service<roarm_msgs::srv::MoveCircleCmd>
  : std::true_type
{
};

template<>
struct is_service_request<roarm_msgs::srv::MoveCircleCmd_Request>
  : std::true_type
{
};

template<>
struct is_service_response<roarm_msgs::srv::MoveCircleCmd_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROARM_MSGS__SRV__DETAIL__MOVE_CIRCLE_CMD__TRAITS_HPP_
