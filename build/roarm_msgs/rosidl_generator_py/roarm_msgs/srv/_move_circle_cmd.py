# generated from rosidl_generator_py/resource/_idl.py.em
# with input from roarm_msgs:srv/MoveCircleCmd.idl
# generated code does not contain a copyright notice

from __future__ import annotations

import collections.abc
import os
import typing

import rosidl_pycommon.interface_base_classes

if typing.TYPE_CHECKING:
    from ctypes import Structure

    class PyCapsule(Structure):
        pass  # don't need to define the full structure


# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
ros_python_check_fields = os.getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MoveCircleCmd_Request(rosidl_pycommon.interface_base_classes.MessageTypeSupportMeta):
    """Metaclass of message 'MoveCircleCmd_Request'."""

    _CREATE_ROS_MESSAGE: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _CONVERT_FROM_PY: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _CONVERT_TO_PY: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _DESTROY_ROS_MESSAGE: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _TYPE_SUPPORT: typing.ClassVar[typing.Optional[PyCapsule]] = None

    class MoveCircleCmd_RequestConstants(typing.TypedDict):
        pass

    __constants: MoveCircleCmd_RequestConstants = {
    }

    @classmethod
    def __import_type_support__(cls) -> None:
        try:
            from rosidl_generator_py import import_type_support  # type: ignore[attr-defined]
            module = import_type_support('roarm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'roarm_msgs.srv.MoveCircleCmd_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_circle_cmd__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_circle_cmd__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_circle_cmd__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_circle_cmd__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_circle_cmd__request

    @classmethod
    def __prepare__(metacls, name: str, bases: tuple[type[typing.Any], ...], /, **kwds: typing.Any) -> collections.abc.MutableMapping[str, object]:
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveCircleCmd_Request(rosidl_pycommon.interface_base_classes.BaseMessage, metaclass=Metaclass_MoveCircleCmd_Request):
    """Message class 'MoveCircleCmd_Request'."""

    __slots__ = [
        '_x0',
        '_y0',
        '_z0',
        '_x1',
        '_y1',
        '_z1',
        '_check_fields',
    ]

    _fields_and_field_types: dict[str, str] = {
        'x0': 'double',
        'y0': 'double',
        'z0': 'double',
        'x1': 'double',
        'y1': 'double',
        'z1': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES: tuple[rosidl_parser.definition.AbstractType, ...] = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, *,
                 x0: typing.Optional[float] = None,  # noqa: E501
                 y0: typing.Optional[float] = None,  # noqa: E501
                 z0: typing.Optional[float] = None,  # noqa: E501
                 x1: typing.Optional[float] = None,  # noqa: E501
                 y1: typing.Optional[float] = None,  # noqa: E501
                 z1: typing.Optional[float] = None,  # noqa: E501
                 check_fields: typing.Optional[bool] = None) -> None:
        if check_fields is not None:
            self._check_fields = check_fields
        else:
            self._check_fields = ros_python_check_fields == '1'
        self.x0 = x0 if x0 is not None else float()
        self.y0 = y0 if y0 is not None else float()
        self.z0 = z0 if z0 is not None else float()
        self.x1 = x1 if x1 is not None else float()
        self.y1 = y1 if y1 is not None else float()
        self.z1 = z1 if z1 is not None else float()

    def __repr__(self) -> str:
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args: list[str] = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    from rosidl_buffer import Buffer as _RosidlBuffer
                    if not isinstance(field, _RosidlBuffer):
                        if self._check_fields:
                            assert fieldstr.startswith('array(')
                        prefix = "array('X', "
                        suffix = ')'
                        fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, MoveCircleCmd_Request):
            return False
        if self.x0 != other.x0:
            return False
        if self.y0 != other.y0:
            return False
        if self.z0 != other.z0:
            return False
        if self.x1 != other.x1:
            return False
        if self.y1 != other.y1:
            return False
        if self.z1 != other.z1:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls) -> dict[str, str]:
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x0(self) -> float:
        """Message field 'x0'."""
        return self._x0

    @x0.setter
    def x0(self, value: float) -> None:

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, float), \
                    "The 'x0' field must be of type 'float'"
                assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                    "The 'x0' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"

        self._x0 = value

    @builtins.property
    def y0(self) -> float:
        """Message field 'y0'."""
        return self._y0

    @y0.setter
    def y0(self, value: float) -> None:

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, float), \
                    "The 'y0' field must be of type 'float'"
                assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                    "The 'y0' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"

        self._y0 = value

    @builtins.property
    def z0(self) -> float:
        """Message field 'z0'."""
        return self._z0

    @z0.setter
    def z0(self, value: float) -> None:

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, float), \
                    "The 'z0' field must be of type 'float'"
                assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                    "The 'z0' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"

        self._z0 = value

    @builtins.property
    def x1(self) -> float:
        """Message field 'x1'."""
        return self._x1

    @x1.setter
    def x1(self, value: float) -> None:

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, float), \
                    "The 'x1' field must be of type 'float'"
                assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                    "The 'x1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"

        self._x1 = value

    @builtins.property
    def y1(self) -> float:
        """Message field 'y1'."""
        return self._y1

    @y1.setter
    def y1(self, value: float) -> None:

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, float), \
                    "The 'y1' field must be of type 'float'"
                assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                    "The 'y1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"

        self._y1 = value

    @builtins.property
    def z1(self) -> float:
        """Message field 'z1'."""
        return self._z1

    @z1.setter
    def z1(self, value: float) -> None:

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, float), \
                    "The 'z1' field must be of type 'float'"
                assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                    "The 'z1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"

        self._z1 = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveCircleCmd_Response(rosidl_pycommon.interface_base_classes.MessageTypeSupportMeta):
    """Metaclass of message 'MoveCircleCmd_Response'."""

    _CREATE_ROS_MESSAGE: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _CONVERT_FROM_PY: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _CONVERT_TO_PY: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _DESTROY_ROS_MESSAGE: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _TYPE_SUPPORT: typing.ClassVar[typing.Optional[PyCapsule]] = None

    class MoveCircleCmd_ResponseConstants(typing.TypedDict):
        pass

    __constants: MoveCircleCmd_ResponseConstants = {
    }

    @classmethod
    def __import_type_support__(cls) -> None:
        try:
            from rosidl_generator_py import import_type_support  # type: ignore[attr-defined]
            module = import_type_support('roarm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'roarm_msgs.srv.MoveCircleCmd_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_circle_cmd__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_circle_cmd__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_circle_cmd__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_circle_cmd__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_circle_cmd__response

    @classmethod
    def __prepare__(metacls, name: str, bases: tuple[type[typing.Any], ...], /, **kwds: typing.Any) -> collections.abc.MutableMapping[str, object]:
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveCircleCmd_Response(rosidl_pycommon.interface_base_classes.BaseMessage, metaclass=Metaclass_MoveCircleCmd_Response):
    """Message class 'MoveCircleCmd_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_check_fields',
    ]

    _fields_and_field_types: dict[str, str] = {
        'success': 'boolean',
        'message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES: tuple[rosidl_parser.definition.AbstractType, ...] = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, *,
                 success: typing.Optional[bool] = None,  # noqa: E501
                 message: typing.Optional[str] = None,  # noqa: E501
                 check_fields: typing.Optional[bool] = None) -> None:
        if check_fields is not None:
            self._check_fields = check_fields
        else:
            self._check_fields = ros_python_check_fields == '1'
        self.success = success if success is not None else bool()
        self.message = message if message is not None else str()

    def __repr__(self) -> str:
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args: list[str] = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    from rosidl_buffer import Buffer as _RosidlBuffer
                    if not isinstance(field, _RosidlBuffer):
                        if self._check_fields:
                            assert fieldstr.startswith('array(')
                        prefix = "array('X', "
                        suffix = ')'
                        fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, MoveCircleCmd_Response):
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls) -> dict[str, str]:
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self) -> bool:
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value: bool) -> None:

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, bool), \
                    "The 'success' field must be of type 'bool'"

        self._success = value

    @builtins.property
    def message(self) -> str:
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value: str) -> None:

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, str), \
                    "The 'message' field must be of type 'str'"

        self._message = value


if typing.TYPE_CHECKING:
    import roarm_msgs.srv  # noqa: E402, I100, I201, I300
    import service_msgs.msg  # noqa: E402, I100, I201, I300


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_MoveCircleCmd_Event(rosidl_pycommon.interface_base_classes.MessageTypeSupportMeta):
    """Metaclass of message 'MoveCircleCmd_Event'."""

    _CREATE_ROS_MESSAGE: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _CONVERT_FROM_PY: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _CONVERT_TO_PY: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _DESTROY_ROS_MESSAGE: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _TYPE_SUPPORT: typing.ClassVar[typing.Optional[PyCapsule]] = None

    class MoveCircleCmd_EventConstants(typing.TypedDict):
        pass

    __constants: MoveCircleCmd_EventConstants = {
    }

    @classmethod
    def __import_type_support__(cls) -> None:
        try:
            from rosidl_generator_py import import_type_support  # type: ignore[attr-defined]
            module = import_type_support('roarm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'roarm_msgs.srv.MoveCircleCmd_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__move_circle_cmd__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__move_circle_cmd__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__move_circle_cmd__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__move_circle_cmd__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__move_circle_cmd__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo._TYPE_SUPPORT is None:
                ServiceEventInfo.__import_type_support__()

    @classmethod
    def __prepare__(metacls, name: str, bases: tuple[type[typing.Any], ...], /, **kwds: typing.Any) -> collections.abc.MutableMapping[str, object]:
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MoveCircleCmd_Event(rosidl_pycommon.interface_base_classes.BaseMessage, metaclass=Metaclass_MoveCircleCmd_Event):
    """Message class 'MoveCircleCmd_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types: dict[str, str] = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<roarm_msgs/MoveCircleCmd_Request, 1>',
        'response': 'sequence<roarm_msgs/MoveCircleCmd_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES: tuple[rosidl_parser.definition.AbstractType, ...] = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['roarm_msgs', 'srv'], 'MoveCircleCmd_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['roarm_msgs', 'srv'], 'MoveCircleCmd_Response'), 1),  # noqa: E501
    )

    def __init__(self, *,
                 info: typing.Optional[service_msgs.msg.ServiceEventInfo] = None,  # noqa: E501
                 request: typing.Optional[collections.abc.Sequence[roarm_msgs.srv.MoveCircleCmd_Request]] = None,  # noqa: E501
                 response: typing.Optional[collections.abc.Sequence[roarm_msgs.srv.MoveCircleCmd_Response]] = None,  # noqa: E501
                 check_fields: typing.Optional[bool] = None) -> None:
        if check_fields is not None:
            self._check_fields = check_fields
        else:
            self._check_fields = ros_python_check_fields == '1'
        from service_msgs.msg import ServiceEventInfo
        self.info = info if info is not None else ServiceEventInfo()
        self.request = request if request is not None else []
        self.response = response if response is not None else []

    def __repr__(self) -> str:
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args: list[str] = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    from rosidl_buffer import Buffer as _RosidlBuffer
                    if not isinstance(field, _RosidlBuffer):
                        if self._check_fields:
                            assert fieldstr.startswith('array(')
                        prefix = "array('X', "
                        suffix = ')'
                        fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, MoveCircleCmd_Event):
            return False
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls) -> dict[str, str]:
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self) -> service_msgs.msg.ServiceEventInfo:
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value: service_msgs.msg.ServiceEventInfo) -> None:
        from service_msgs.msg import ServiceEventInfo

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, ServiceEventInfo), \
                    "The 'info' field must be a sub message of type 'ServiceEventInfo'"

        self._info = value

    @builtins.property
    def request(self) -> typing.Annotated[typing.Any, list[roarm_msgs.srv.MoveCircleCmd_Request]]:   # typing.Annotated can be remove after mypy 1.16+ see mypy#3004
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value: collections.abc.Sequence[roarm_msgs.srv.MoveCircleCmd_Request]) -> None:
        if isinstance(value, collections.abc.Set):
            import warnings
            warnings.warn(
                'Using set or subclass of set is deprecated,'
                ' please use a subclass of collections.abc.Sequence like list',
                DeprecationWarning)
        from roarm_msgs.srv import MoveCircleCmd_Request

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    ((isinstance(value, collections.abc.Sequence) or
                     isinstance(value, collections.abc.Set)) and
                     not isinstance(value, str) and
                     not isinstance(value, collections.UserString) and
                     len(value) <= 1 and
                     all(isinstance(v, MoveCircleCmd_Request) for v in value) and
                     True), \
                    "The 'request' field must be sequence with length <= 1 and each value of type 'MoveCircleCmd_Request'"

        if isinstance(value, list):
            self._request = value
            return
        self._request = list(value)

    @builtins.property
    def response(self) -> typing.Annotated[typing.Any, list[roarm_msgs.srv.MoveCircleCmd_Response]]:   # typing.Annotated can be remove after mypy 1.16+ see mypy#3004
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value: collections.abc.Sequence[roarm_msgs.srv.MoveCircleCmd_Response]) -> None:
        if isinstance(value, collections.abc.Set):
            import warnings
            warnings.warn(
                'Using set or subclass of set is deprecated,'
                ' please use a subclass of collections.abc.Sequence like list',
                DeprecationWarning)
        from roarm_msgs.srv import MoveCircleCmd_Response

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    ((isinstance(value, collections.abc.Sequence) or
                     isinstance(value, collections.abc.Set)) and
                     not isinstance(value, str) and
                     not isinstance(value, collections.UserString) and
                     len(value) <= 1 and
                     all(isinstance(v, MoveCircleCmd_Response) for v in value) and
                     True), \
                    "The 'response' field must be sequence with length <= 1 and each value of type 'MoveCircleCmd_Response'"

        if isinstance(value, list):
            self._response = value
            return
        self._response = list(value)


if typing.TYPE_CHECKING:
    from typing_extensions import TypeAlias  # noqa: I100, I300


class Metaclass_MoveCircleCmd(rosidl_pycommon.interface_base_classes.ServiceTypeSupportMeta):
    """Metaclass of service 'MoveCircleCmd'."""

    _TYPE_SUPPORT: typing.ClassVar[typing.Optional[PyCapsule]] = None

    @classmethod
    def __import_type_support__(cls) -> None:
        try:
            from rosidl_generator_py import import_type_support  # type: ignore[attr-defined]
            module = import_type_support('roarm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'roarm_msgs.srv.MoveCircleCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__move_circle_cmd

            from roarm_msgs.srv import _move_circle_cmd
            if _move_circle_cmd.Metaclass_MoveCircleCmd_Request._TYPE_SUPPORT is None:
                _move_circle_cmd.Metaclass_MoveCircleCmd_Request.__import_type_support__()
            if _move_circle_cmd.Metaclass_MoveCircleCmd_Response._TYPE_SUPPORT is None:
                _move_circle_cmd.Metaclass_MoveCircleCmd_Response.__import_type_support__()
            if _move_circle_cmd.Metaclass_MoveCircleCmd_Event._TYPE_SUPPORT is None:
                _move_circle_cmd.Metaclass_MoveCircleCmd_Event.__import_type_support__()


class MoveCircleCmd(rosidl_pycommon.interface_base_classes.BaseService[
    MoveCircleCmd_Request,
    MoveCircleCmd_Response
], metaclass=Metaclass_MoveCircleCmd):
    Request: TypeAlias = MoveCircleCmd_Request
    Response: TypeAlias = MoveCircleCmd_Response
    Event: TypeAlias = MoveCircleCmd_Event

    # Should eventually be typing.NoReturn. See mypy#14044
    def __init__(self) -> None:
        raise NotImplementedError('Service classes can not be instantiated')
