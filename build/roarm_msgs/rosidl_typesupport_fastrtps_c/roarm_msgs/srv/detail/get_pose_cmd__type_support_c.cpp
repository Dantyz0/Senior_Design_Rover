// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from roarm_msgs:srv/GetPoseCmd.idl
// generated code does not contain a copyright notice
#include "roarm_msgs/srv/detail/get_pose_cmd__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "roarm_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roarm_msgs/srv/detail/get_pose_cmd__struct.h"
#include "roarm_msgs/srv/detail/get_pose_cmd__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GetPoseCmd_Request__ros_msg_type = roarm_msgs__srv__GetPoseCmd_Request;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_serialize_roarm_msgs__srv__GetPoseCmd_Request(
  const roarm_msgs__srv__GetPoseCmd_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Request(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Request * ros_message)
{
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t get_serialized_size_roarm_msgs__srv__GetPoseCmd_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetPoseCmd_Request__ros_msg_type * ros_message = static_cast<const _GetPoseCmd_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t max_serialized_size_roarm_msgs__srv__GetPoseCmd_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: structure_needs_at_least_one_member
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roarm_msgs__srv__GetPoseCmd_Request;
    is_plain =
      (
      offsetof(DataType, structure_needs_at_least_one_member) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_serialize_key_roarm_msgs__srv__GetPoseCmd_Request(
  const roarm_msgs__srv__GetPoseCmd_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t get_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetPoseCmd_Request__ros_msg_type * ros_message = static_cast<const _GetPoseCmd_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t max_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: structure_needs_at_least_one_member
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roarm_msgs__srv__GetPoseCmd_Request;
    is_plain =
      (
      offsetof(DataType, structure_needs_at_least_one_member) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GetPoseCmd_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const roarm_msgs__srv__GetPoseCmd_Request * ros_message = static_cast<const roarm_msgs__srv__GetPoseCmd_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_roarm_msgs__srv__GetPoseCmd_Request(ros_message, cdr);
}

static bool _GetPoseCmd_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  roarm_msgs__srv__GetPoseCmd_Request * ros_message = static_cast<roarm_msgs__srv__GetPoseCmd_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Request(cdr, ros_message);
}

static uint32_t _GetPoseCmd_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_roarm_msgs__srv__GetPoseCmd_Request(
      untyped_ros_message, 0));
}

static size_t _GetPoseCmd_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_roarm_msgs__srv__GetPoseCmd_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Request(
  const roarm_msgs__srv__GetPoseCmd_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Request(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Request * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}  // NOLINT(readability/fn_size)

static bool _GetPoseCmd_Request__cdr_serialize_with_endpoint(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const roarm_msgs__srv__GetPoseCmd_Request * ros_message =
    static_cast<const roarm_msgs__srv__GetPoseCmd_Request *>(untyped_ros_message);
  return cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Request(
    ros_message, cdr, endpoint_info, serialization_context);
}

static bool _GetPoseCmd_Request__cdr_deserialize_with_endpoint(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  roarm_msgs__srv__GetPoseCmd_Request * ros_message =
    static_cast<roarm_msgs__srv__GetPoseCmd_Request *>(untyped_ros_message);
  return cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Request(
    cdr, ros_message, endpoint_info, serialization_context);
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Request()
{
  return
    false;
}

static message_type_support_callbacks_t __callbacks_GetPoseCmd_Request = {
  "roarm_msgs::srv",
  "GetPoseCmd_Request",
  _GetPoseCmd_Request__cdr_serialize,
  _GetPoseCmd_Request__cdr_deserialize,
  _GetPoseCmd_Request__get_serialized_size,
  _GetPoseCmd_Request__max_serialized_size,
  nullptr,
  has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Request(),
  _GetPoseCmd_Request__cdr_serialize_with_endpoint,
  _GetPoseCmd_Request__cdr_deserialize_with_endpoint
};

static rosidl_message_type_support_t _GetPoseCmd_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetPoseCmd_Request,
  get_message_typesupport_handle_function,
  &roarm_msgs__srv__GetPoseCmd_Request__get_type_hash,
  &roarm_msgs__srv__GetPoseCmd_Request__get_type_description,
  &roarm_msgs__srv__GetPoseCmd_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roarm_msgs, srv, GetPoseCmd_Request)() {
  return &_GetPoseCmd_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "roarm_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "roarm_msgs/srv/detail/get_pose_cmd__struct.h"
// already included above
// #include "roarm_msgs/srv/detail/get_pose_cmd__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GetPoseCmd_Response__ros_msg_type = roarm_msgs__srv__GetPoseCmd_Response;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_serialize_roarm_msgs__srv__GetPoseCmd_Response(
  const roarm_msgs__srv__GetPoseCmd_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: roll
  {
    cdr << ros_message->roll;
  }

  // Field name: pitch
  {
    cdr << ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Response(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Response * ros_message)
{
  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: z
  {
    cdr >> ros_message->z;
  }

  // Field name: roll
  {
    cdr >> ros_message->roll;
  }

  // Field name: pitch
  {
    cdr >> ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr >> ros_message->yaw;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t get_serialized_size_roarm_msgs__srv__GetPoseCmd_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetPoseCmd_Response__ros_msg_type * ros_message = static_cast<const _GetPoseCmd_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: roll
  {
    size_t item_size = sizeof(ros_message->roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pitch
  {
    size_t item_size = sizeof(ros_message->pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw
  {
    size_t item_size = sizeof(ros_message->yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t max_serialized_size_roarm_msgs__srv__GetPoseCmd_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: roll
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: pitch
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roarm_msgs__srv__GetPoseCmd_Response;
    is_plain =
      (
      offsetof(DataType, yaw) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_serialize_key_roarm_msgs__srv__GetPoseCmd_Response(
  const roarm_msgs__srv__GetPoseCmd_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: roll
  {
    cdr << ros_message->roll;
  }

  // Field name: pitch
  {
    cdr << ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t get_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetPoseCmd_Response__ros_msg_type * ros_message = static_cast<const _GetPoseCmd_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: roll
  {
    size_t item_size = sizeof(ros_message->roll);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: pitch
  {
    size_t item_size = sizeof(ros_message->pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: yaw
  {
    size_t item_size = sizeof(ros_message->yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t max_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: roll
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: pitch
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: yaw
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roarm_msgs__srv__GetPoseCmd_Response;
    is_plain =
      (
      offsetof(DataType, yaw) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GetPoseCmd_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const roarm_msgs__srv__GetPoseCmd_Response * ros_message = static_cast<const roarm_msgs__srv__GetPoseCmd_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_roarm_msgs__srv__GetPoseCmd_Response(ros_message, cdr);
}

static bool _GetPoseCmd_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  roarm_msgs__srv__GetPoseCmd_Response * ros_message = static_cast<roarm_msgs__srv__GetPoseCmd_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Response(cdr, ros_message);
}

static uint32_t _GetPoseCmd_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_roarm_msgs__srv__GetPoseCmd_Response(
      untyped_ros_message, 0));
}

static size_t _GetPoseCmd_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_roarm_msgs__srv__GetPoseCmd_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Response(
  const roarm_msgs__srv__GetPoseCmd_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: roll
  {
    cdr << ros_message->roll;
  }

  // Field name: pitch
  {
    cdr << ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Response(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Response * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: z
  {
    cdr >> ros_message->z;
  }

  // Field name: roll
  {
    cdr >> ros_message->roll;
  }

  // Field name: pitch
  {
    cdr >> ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr >> ros_message->yaw;
  }

  return true;
}  // NOLINT(readability/fn_size)

static bool _GetPoseCmd_Response__cdr_serialize_with_endpoint(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const roarm_msgs__srv__GetPoseCmd_Response * ros_message =
    static_cast<const roarm_msgs__srv__GetPoseCmd_Response *>(untyped_ros_message);
  return cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Response(
    ros_message, cdr, endpoint_info, serialization_context);
}

static bool _GetPoseCmd_Response__cdr_deserialize_with_endpoint(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  roarm_msgs__srv__GetPoseCmd_Response * ros_message =
    static_cast<roarm_msgs__srv__GetPoseCmd_Response *>(untyped_ros_message);
  return cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Response(
    cdr, ros_message, endpoint_info, serialization_context);
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Response()
{
  return
    false;
}

static message_type_support_callbacks_t __callbacks_GetPoseCmd_Response = {
  "roarm_msgs::srv",
  "GetPoseCmd_Response",
  _GetPoseCmd_Response__cdr_serialize,
  _GetPoseCmd_Response__cdr_deserialize,
  _GetPoseCmd_Response__get_serialized_size,
  _GetPoseCmd_Response__max_serialized_size,
  nullptr,
  has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Response(),
  _GetPoseCmd_Response__cdr_serialize_with_endpoint,
  _GetPoseCmd_Response__cdr_deserialize_with_endpoint
};

static rosidl_message_type_support_t _GetPoseCmd_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetPoseCmd_Response,
  get_message_typesupport_handle_function,
  &roarm_msgs__srv__GetPoseCmd_Response__get_type_hash,
  &roarm_msgs__srv__GetPoseCmd_Response__get_type_description,
  &roarm_msgs__srv__GetPoseCmd_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roarm_msgs, srv, GetPoseCmd_Response)() {
  return &_GetPoseCmd_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "roarm_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "roarm_msgs/srv/detail/get_pose_cmd__struct.h"
// already included above
// #include "roarm_msgs/srv/detail/get_pose_cmd__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions

bool cdr_serialize_roarm_msgs__srv__GetPoseCmd_Request(
  const roarm_msgs__srv__GetPoseCmd_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Request(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Request * ros_message);

size_t get_serialized_size_roarm_msgs__srv__GetPoseCmd_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_roarm_msgs__srv__GetPoseCmd_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_roarm_msgs__srv__GetPoseCmd_Request(
  const roarm_msgs__srv__GetPoseCmd_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roarm_msgs, srv, GetPoseCmd_Request)();

bool cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Request(
  const roarm_msgs__srv__GetPoseCmd_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context);

bool cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Request(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Request * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context);

bool has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Request();

bool cdr_serialize_roarm_msgs__srv__GetPoseCmd_Response(
  const roarm_msgs__srv__GetPoseCmd_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Response(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Response * ros_message);

size_t get_serialized_size_roarm_msgs__srv__GetPoseCmd_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_roarm_msgs__srv__GetPoseCmd_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_roarm_msgs__srv__GetPoseCmd_Response(
  const roarm_msgs__srv__GetPoseCmd_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roarm_msgs, srv, GetPoseCmd_Response)();

bool cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Response(
  const roarm_msgs__srv__GetPoseCmd_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context);

bool cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Response(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Response * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context);

bool has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Response();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
bool cdr_serialize_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
bool cdr_deserialize_service_msgs__msg__ServiceEventInfo(
  eprosima::fastcdr::Cdr & cdr,
  service_msgs__msg__ServiceEventInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
bool cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
size_t get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
size_t max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
bool cdr_serialize_with_endpoint_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
bool cdr_deserialize_with_endpoint_service_msgs__msg__ServiceEventInfo(
  eprosima::fastcdr::Cdr & cdr,
  service_msgs__msg__ServiceEventInfo * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_roarm_msgs
bool has_buffer_fields_service_msgs__msg__ServiceEventInfo();


using _GetPoseCmd_Event__ros_msg_type = roarm_msgs__srv__GetPoseCmd_Event;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_serialize_roarm_msgs__srv__GetPoseCmd_Event(
  const roarm_msgs__srv__GetPoseCmd_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_roarm_msgs__srv__GetPoseCmd_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_roarm_msgs__srv__GetPoseCmd_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Event(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Event * ros_message)
{
  // Field name: info
  {
    cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->request.data) {
      roarm_msgs__srv__GetPoseCmd_Request__Sequence__fini(&ros_message->request);
    }
    if (!roarm_msgs__srv__GetPoseCmd_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->response.data) {
      roarm_msgs__srv__GetPoseCmd_Response__Sequence__fini(&ros_message->response);
    }
    if (!roarm_msgs__srv__GetPoseCmd_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t get_serialized_size_roarm_msgs__srv__GetPoseCmd_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetPoseCmd_Event__ros_msg_type * ros_message = static_cast<const _GetPoseCmd_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_roarm_msgs__srv__GetPoseCmd_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_roarm_msgs__srv__GetPoseCmd_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t max_serialized_size_roarm_msgs__srv__GetPoseCmd_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_roarm_msgs__srv__GetPoseCmd_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_roarm_msgs__srv__GetPoseCmd_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roarm_msgs__srv__GetPoseCmd_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_serialize_key_roarm_msgs__srv__GetPoseCmd_Event(
  const roarm_msgs__srv__GetPoseCmd_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_roarm_msgs__srv__GetPoseCmd_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_roarm_msgs__srv__GetPoseCmd_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t get_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GetPoseCmd_Event__ros_msg_type * ros_message = static_cast<const _GetPoseCmd_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
size_t max_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Event(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_roarm_msgs__srv__GetPoseCmd_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = roarm_msgs__srv__GetPoseCmd_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _GetPoseCmd_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const roarm_msgs__srv__GetPoseCmd_Event * ros_message = static_cast<const roarm_msgs__srv__GetPoseCmd_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_roarm_msgs__srv__GetPoseCmd_Event(ros_message, cdr);
}

static bool _GetPoseCmd_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  roarm_msgs__srv__GetPoseCmd_Event * ros_message = static_cast<roarm_msgs__srv__GetPoseCmd_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_roarm_msgs__srv__GetPoseCmd_Event(cdr, ros_message);
}

static uint32_t _GetPoseCmd_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_roarm_msgs__srv__GetPoseCmd_Event(
      untyped_ros_message, 0));
}

static size_t _GetPoseCmd_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_roarm_msgs__srv__GetPoseCmd_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Event(
  const roarm_msgs__srv__GetPoseCmd_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: info
  {
    cdr_serialize_with_endpoint_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr, endpoint_info, serialization_context);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Request(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Response(
        &array_ptr[i], cdr, endpoint_info, serialization_context);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Event(
  eprosima::fastcdr::Cdr & cdr,
  roarm_msgs__srv__GetPoseCmd_Event * ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  (void)ros_message;
  (void)endpoint_info;
  (void)serialization_context;
  // Field name: info
  {
    cdr_deserialize_with_endpoint_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info, endpoint_info, serialization_context);
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->request.data) {
      roarm_msgs__srv__GetPoseCmd_Request__Sequence__fini(&ros_message->request);
    }
    if (!roarm_msgs__srv__GetPoseCmd_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Request(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.get_state();
    bool correct_size = cdr.jump(size);
    cdr.set_state(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->response.data) {
      roarm_msgs__srv__GetPoseCmd_Response__Sequence__fini(&ros_message->response);
    }
    if (!roarm_msgs__srv__GetPoseCmd_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Response(cdr, &array_ptr[i], endpoint_info, serialization_context);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

static bool _GetPoseCmd_Event__cdr_serialize_with_endpoint(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const roarm_msgs__srv__GetPoseCmd_Event * ros_message =
    static_cast<const roarm_msgs__srv__GetPoseCmd_Event *>(untyped_ros_message);
  return cdr_serialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Event(
    ros_message, cdr, endpoint_info, serialization_context);
}

static bool _GetPoseCmd_Event__cdr_deserialize_with_endpoint(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message,
  const rmw_topic_endpoint_info_t & endpoint_info,
  const rosidl_typesupport_fastrtps_cpp::BufferSerializationContext & serialization_context)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  roarm_msgs__srv__GetPoseCmd_Event * ros_message =
    static_cast<roarm_msgs__srv__GetPoseCmd_Event *>(untyped_ros_message);
  return cdr_deserialize_with_endpoint_roarm_msgs__srv__GetPoseCmd_Event(
    cdr, ros_message, endpoint_info, serialization_context);
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_roarm_msgs
bool has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Event()
{
  return
    has_buffer_fields_service_msgs__msg__ServiceEventInfo() ||
    has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Request() ||
    has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Response();
}

static message_type_support_callbacks_t __callbacks_GetPoseCmd_Event = {
  "roarm_msgs::srv",
  "GetPoseCmd_Event",
  _GetPoseCmd_Event__cdr_serialize,
  _GetPoseCmd_Event__cdr_deserialize,
  _GetPoseCmd_Event__get_serialized_size,
  _GetPoseCmd_Event__max_serialized_size,
  nullptr,
  has_buffer_fields_roarm_msgs__srv__GetPoseCmd_Event(),
  _GetPoseCmd_Event__cdr_serialize_with_endpoint,
  _GetPoseCmd_Event__cdr_deserialize_with_endpoint
};

static rosidl_message_type_support_t _GetPoseCmd_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GetPoseCmd_Event,
  get_message_typesupport_handle_function,
  &roarm_msgs__srv__GetPoseCmd_Event__get_type_hash,
  &roarm_msgs__srv__GetPoseCmd_Event__get_type_description,
  &roarm_msgs__srv__GetPoseCmd_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roarm_msgs, srv, GetPoseCmd_Event)() {
  return &_GetPoseCmd_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "roarm_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "roarm_msgs/srv/get_pose_cmd.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GetPoseCmd__callbacks = {
  "roarm_msgs::srv",
  "GetPoseCmd",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roarm_msgs, srv, GetPoseCmd_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roarm_msgs, srv, GetPoseCmd_Response)(),
};

static rosidl_service_type_support_t GetPoseCmd__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &GetPoseCmd__callbacks,
  get_service_typesupport_handle_function,
  &_GetPoseCmd_Request__type_support,
  &_GetPoseCmd_Response__type_support,
  &_GetPoseCmd_Event__type_support,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    roarm_msgs,
    srv,
    GetPoseCmd
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    roarm_msgs,
    srv,
    GetPoseCmd
  ),
  &roarm_msgs__srv__GetPoseCmd__get_type_hash,
  &roarm_msgs__srv__GetPoseCmd__get_type_description,
  &roarm_msgs__srv__GetPoseCmd__get_type_description_sources,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, roarm_msgs, srv, GetPoseCmd)() {
  return &GetPoseCmd__handle;
}

#if defined(__cplusplus)
}
#endif
