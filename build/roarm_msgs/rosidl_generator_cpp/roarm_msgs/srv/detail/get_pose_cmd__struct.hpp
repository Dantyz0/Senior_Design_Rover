// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from roarm_msgs:srv/GetPoseCmd.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "roarm_msgs/srv/get_pose_cmd.hpp"


#ifndef ROARM_MSGS__SRV__DETAIL__GET_POSE_CMD__STRUCT_HPP_
#define ROARM_MSGS__SRV__DETAIL__GET_POSE_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_buffer/buffer.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__roarm_msgs__srv__GetPoseCmd_Request __attribute__((deprecated))
#else
# define DEPRECATED__roarm_msgs__srv__GetPoseCmd_Request __declspec(deprecated)
#endif

namespace roarm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetPoseCmd_Request_
{
  using Type = GetPoseCmd_Request_<ContainerAllocator>;

  explicit GetPoseCmd_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetPoseCmd_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roarm_msgs__srv__GetPoseCmd_Request
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roarm_msgs__srv__GetPoseCmd_Request
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPoseCmd_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPoseCmd_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPoseCmd_Request_

// alias to use template instance with default allocator
using GetPoseCmd_Request =
  roarm_msgs::srv::GetPoseCmd_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace roarm_msgs


#ifndef _WIN32
# define DEPRECATED__roarm_msgs__srv__GetPoseCmd_Response __attribute__((deprecated))
#else
# define DEPRECATED__roarm_msgs__srv__GetPoseCmd_Response __declspec(deprecated)
#endif

namespace roarm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetPoseCmd_Response_
{
  using Type = GetPoseCmd_Response_<ContainerAllocator>;

  explicit GetPoseCmd_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  explicit GetPoseCmd_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roarm_msgs__srv__GetPoseCmd_Response
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roarm_msgs__srv__GetPoseCmd_Response
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPoseCmd_Response_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPoseCmd_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPoseCmd_Response_

// alias to use template instance with default allocator
using GetPoseCmd_Response =
  roarm_msgs::srv::GetPoseCmd_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace roarm_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__roarm_msgs__srv__GetPoseCmd_Event __attribute__((deprecated))
#else
# define DEPRECATED__roarm_msgs__srv__GetPoseCmd_Event __declspec(deprecated)
#endif

namespace roarm_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetPoseCmd_Event_
{
  using Type = GetPoseCmd_Event_<ContainerAllocator>;

  explicit GetPoseCmd_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetPoseCmd_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<roarm_msgs::srv::GetPoseCmd_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<roarm_msgs::srv::GetPoseCmd_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__roarm_msgs__srv__GetPoseCmd_Event
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__roarm_msgs__srv__GetPoseCmd_Event
    std::shared_ptr<roarm_msgs::srv::GetPoseCmd_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPoseCmd_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPoseCmd_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPoseCmd_Event_

// alias to use template instance with default allocator
using GetPoseCmd_Event =
  roarm_msgs::srv::GetPoseCmd_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace roarm_msgs

namespace roarm_msgs
{

namespace srv
{

struct GetPoseCmd
{
  using Request = roarm_msgs::srv::GetPoseCmd_Request;
  using Response = roarm_msgs::srv::GetPoseCmd_Response;
  using Event = roarm_msgs::srv::GetPoseCmd_Event;
};

}  // namespace srv

}  // namespace roarm_msgs

#endif  // ROARM_MSGS__SRV__DETAIL__GET_POSE_CMD__STRUCT_HPP_
