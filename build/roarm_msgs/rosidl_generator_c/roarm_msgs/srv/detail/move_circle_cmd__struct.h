// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from roarm_msgs:srv/MoveCircleCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roarm_msgs/srv/move_circle_cmd.h"


#ifndef ROARM_MSGS__SRV__DETAIL__MOVE_CIRCLE_CMD__STRUCT_H_
#define ROARM_MSGS__SRV__DETAIL__MOVE_CIRCLE_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/MoveCircleCmd in the package roarm_msgs.
typedef struct roarm_msgs__srv__MoveCircleCmd_Request
{
  double x0;
  double y0;
  double z0;
  double x1;
  double y1;
  double z1;
} roarm_msgs__srv__MoveCircleCmd_Request;

// Struct for a sequence of roarm_msgs__srv__MoveCircleCmd_Request.
typedef struct roarm_msgs__srv__MoveCircleCmd_Request__Sequence
{
  roarm_msgs__srv__MoveCircleCmd_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_msgs__srv__MoveCircleCmd_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/MoveCircleCmd in the package roarm_msgs.
typedef struct roarm_msgs__srv__MoveCircleCmd_Response
{
  bool success;
  rosidl_runtime_c__String message;
} roarm_msgs__srv__MoveCircleCmd_Response;

// Struct for a sequence of roarm_msgs__srv__MoveCircleCmd_Response.
typedef struct roarm_msgs__srv__MoveCircleCmd_Response__Sequence
{
  roarm_msgs__srv__MoveCircleCmd_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_msgs__srv__MoveCircleCmd_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  roarm_msgs__srv__MoveCircleCmd_Event__request__MAX_SIZE = 1
};
// response
enum
{
  roarm_msgs__srv__MoveCircleCmd_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/MoveCircleCmd in the package roarm_msgs.
typedef struct roarm_msgs__srv__MoveCircleCmd_Event
{
  service_msgs__msg__ServiceEventInfo info;
  roarm_msgs__srv__MoveCircleCmd_Request__Sequence request;
  roarm_msgs__srv__MoveCircleCmd_Response__Sequence response;
} roarm_msgs__srv__MoveCircleCmd_Event;

// Struct for a sequence of roarm_msgs__srv__MoveCircleCmd_Event.
typedef struct roarm_msgs__srv__MoveCircleCmd_Event__Sequence
{
  roarm_msgs__srv__MoveCircleCmd_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} roarm_msgs__srv__MoveCircleCmd_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROARM_MSGS__SRV__DETAIL__MOVE_CIRCLE_CMD__STRUCT_H_
