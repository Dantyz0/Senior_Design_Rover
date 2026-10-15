# generated from rosidl_generator_py/resource/_idl.py.em
# with input from roarm_msgs:msg/ServoStatus.idl
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

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ServoStatus(rosidl_pycommon.interface_base_classes.MessageTypeSupportMeta):
    """Metaclass of message 'ServoStatus'."""

    _CREATE_ROS_MESSAGE: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _CONVERT_FROM_PY: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _CONVERT_TO_PY: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _DESTROY_ROS_MESSAGE: typing.ClassVar[typing.Optional[PyCapsule]] = None
    _TYPE_SUPPORT: typing.ClassVar[typing.Optional[PyCapsule]] = None

    class ServoStatusConstants(typing.TypedDict):
        INVALID: typing.Literal[-1]
        NO_WARNING: typing.Literal[0]
        DECELERATE_FOR_APPROACHING_SINGULARITY: typing.Literal[1]
        HALT_FOR_SINGULARITY: typing.Literal[2]
        DECELERATE_FOR_LEAVING_SINGULARITY: typing.Literal[3]
        DECELERATE_FOR_COLLISION: typing.Literal[4]
        HALT_FOR_COLLISION: typing.Literal[5]
        JOINT_BOUND: typing.Literal[6]

    __constants: ServoStatusConstants = {
        'INVALID': -1,
        'NO_WARNING': 0,
        'DECELERATE_FOR_APPROACHING_SINGULARITY': 1,
        'HALT_FOR_SINGULARITY': 2,
        'DECELERATE_FOR_LEAVING_SINGULARITY': 3,
        'DECELERATE_FOR_COLLISION': 4,
        'HALT_FOR_COLLISION': 5,
        'JOINT_BOUND': 6,
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
                'roarm_msgs.msg.ServoStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__servo_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__servo_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__servo_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__servo_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__servo_status

    @classmethod
    def __prepare__(metacls, name: str, bases: tuple[type[typing.Any], ...], /, **kwds: typing.Any) -> collections.abc.MutableMapping[str, object]:
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'INVALID': metacls.__constants['INVALID'],
            'NO_WARNING': metacls.__constants['NO_WARNING'],
            'DECELERATE_FOR_APPROACHING_SINGULARITY': metacls.__constants['DECELERATE_FOR_APPROACHING_SINGULARITY'],
            'HALT_FOR_SINGULARITY': metacls.__constants['HALT_FOR_SINGULARITY'],
            'DECELERATE_FOR_LEAVING_SINGULARITY': metacls.__constants['DECELERATE_FOR_LEAVING_SINGULARITY'],
            'DECELERATE_FOR_COLLISION': metacls.__constants['DECELERATE_FOR_COLLISION'],
            'HALT_FOR_COLLISION': metacls.__constants['HALT_FOR_COLLISION'],
            'JOINT_BOUND': metacls.__constants['JOINT_BOUND'],
        }

    @property
    def INVALID(self) -> typing.Literal[-1]:
        """Message constant 'INVALID'."""
        return Metaclass_ServoStatus.__constants['INVALID']

    @property
    def NO_WARNING(self) -> typing.Literal[0]:
        """Message constant 'NO_WARNING'."""
        return Metaclass_ServoStatus.__constants['NO_WARNING']

    @property
    def DECELERATE_FOR_APPROACHING_SINGULARITY(self) -> typing.Literal[1]:
        """Message constant 'DECELERATE_FOR_APPROACHING_SINGULARITY'."""
        return Metaclass_ServoStatus.__constants['DECELERATE_FOR_APPROACHING_SINGULARITY']

    @property
    def HALT_FOR_SINGULARITY(self) -> typing.Literal[2]:
        """Message constant 'HALT_FOR_SINGULARITY'."""
        return Metaclass_ServoStatus.__constants['HALT_FOR_SINGULARITY']

    @property
    def DECELERATE_FOR_LEAVING_SINGULARITY(self) -> typing.Literal[3]:
        """Message constant 'DECELERATE_FOR_LEAVING_SINGULARITY'."""
        return Metaclass_ServoStatus.__constants['DECELERATE_FOR_LEAVING_SINGULARITY']

    @property
    def DECELERATE_FOR_COLLISION(self) -> typing.Literal[4]:
        """Message constant 'DECELERATE_FOR_COLLISION'."""
        return Metaclass_ServoStatus.__constants['DECELERATE_FOR_COLLISION']

    @property
    def HALT_FOR_COLLISION(self) -> typing.Literal[5]:
        """Message constant 'HALT_FOR_COLLISION'."""
        return Metaclass_ServoStatus.__constants['HALT_FOR_COLLISION']

    @property
    def JOINT_BOUND(self) -> typing.Literal[6]:
        """Message constant 'JOINT_BOUND'."""
        return Metaclass_ServoStatus.__constants['JOINT_BOUND']


class ServoStatus(rosidl_pycommon.interface_base_classes.BaseMessage, metaclass=Metaclass_ServoStatus):
    """
    Message class 'ServoStatus'.

    Constants:
      INVALID
      NO_WARNING
      DECELERATE_FOR_APPROACHING_SINGULARITY
      HALT_FOR_SINGULARITY
      DECELERATE_FOR_LEAVING_SINGULARITY
      DECELERATE_FOR_COLLISION
      HALT_FOR_COLLISION
      JOINT_BOUND
    """

    __slots__ = [
        '_code',
        '_message',
        '_check_fields',
    ]

    _fields_and_field_types: dict[str, str] = {
        'code': 'int8',
        'message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES: tuple[rosidl_parser.definition.AbstractType, ...] = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, *,
                 code: typing.Optional[int] = None,  # noqa: E501
                 message: typing.Optional[str] = None,  # noqa: E501
                 check_fields: typing.Optional[bool] = None) -> None:
        if check_fields is not None:
            self._check_fields = check_fields
        else:
            self._check_fields = ros_python_check_fields == '1'
        self.code = code if code is not None else int()
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
        if not isinstance(other, ServoStatus):
            return False
        if self.code != other.code:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls) -> dict[str, str]:
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def code(self) -> int:
        """Message field 'code'."""
        return self._code

    @code.setter
    def code(self, value: int) -> None:

        if self._check_fields:
            if False:  # Done for templating alignment
                pass
            else:
                assert \
                    isinstance(value, int), \
                    "The 'code' field must be of type 'int'"
                assert value >= -128 and value < 128, \
                    "The 'code' field must be an integer in [-128, 127]"

        self._code = value

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
