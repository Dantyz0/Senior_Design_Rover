// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roarm_msgs:srv/MoveLineCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roarm_msgs/srv/move_line_cmd.h"


#ifndef ROARM_MSGS__SRV__DETAIL__MOVE_LINE_CMD__STRUCT_H_
#define ROARM_MSGS__SRV__DETAIL__MOVE_LINE_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MoveLineCmd in the package roarm_msgs.
typedef struct roarm_msgs__srv__MoveLineCmd_Request
{
  double x;
  double y;
  double z;
} roarm_msgs__srv__MoveLineCmd_Request;

// Struct for a sequence of roarm_msgs__srv__MoveLineCmd_Request.
typedef struct roarm_msgs__srv__MoveLineCmd_Request__Sequence
{
  roarm_msgs__srv__MoveLineCmd_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_msgs__srv__MoveLineCmd_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MoveLineCmd in the package roarm_msgs.
typedef struct roarm_msgs__srv__MoveLineCmd_Response
{
  bool success;
  rosidl_runtime_c__String message;
} roarm_msgs__srv__MoveLineCmd_Response;

// Struct for a sequence of roarm_msgs__srv__MoveLineCmd_Response.
typedef struct roarm_msgs__srv__MoveLineCmd_Response__Sequence
{
  roarm_msgs__srv__MoveLineCmd_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_msgs__srv__MoveLineCmd_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  roarm_msgs__srv__MoveLineCmd_Event__request__MAX_SIZE = 1
};
// response
enum
{
  roarm_msgs__srv__MoveLineCmd_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/MoveLineCmd in the package roarm_msgs.
typedef struct roarm_msgs__srv__MoveLineCmd_Event
{
  service_msgs__msg__ServiceEventInfo info;
  roarm_msgs__srv__MoveLineCmd_Request__Sequence request;
  roarm_msgs__srv__MoveLineCmd_Response__Sequence response;
} roarm_msgs__srv__MoveLineCmd_Event;

// Struct for a sequence of roarm_msgs__srv__MoveLineCmd_Event.
typedef struct roarm_msgs__srv__MoveLineCmd_Event__Sequence
{
  roarm_msgs__srv__MoveLineCmd_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_msgs__srv__MoveLineCmd_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROARM_MSGS__SRV__DETAIL__MOVE_LINE_CMD__STRUCT_H_
