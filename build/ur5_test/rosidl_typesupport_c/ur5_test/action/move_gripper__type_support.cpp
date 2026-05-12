// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from ur5_test:action/MoveGripper.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "ur5_test/action/detail/move_gripper__struct.h"
#include "ur5_test/action/detail/move_gripper__type_support.h"
#include "ur5_test/action/detail/move_gripper__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_Goal_type_support_ids_t;

static const _MoveGripper_Goal_type_support_ids_t _MoveGripper_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_Goal_type_support_symbol_names_t _MoveGripper_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_Goal)),
  }
};

typedef struct _MoveGripper_Goal_type_support_data_t
{
  void * data[2];
} _MoveGripper_Goal_type_support_data_t;

static _MoveGripper_Goal_type_support_data_t _MoveGripper_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_Goal_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_Goal__get_type_hash,
  &ur5_test__action__MoveGripper_Goal__get_type_description,
  &ur5_test__action__MoveGripper_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_Goal)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_Result_type_support_ids_t;

static const _MoveGripper_Result_type_support_ids_t _MoveGripper_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_Result_type_support_symbol_names_t _MoveGripper_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_Result)),
  }
};

typedef struct _MoveGripper_Result_type_support_data_t
{
  void * data[2];
} _MoveGripper_Result_type_support_data_t;

static _MoveGripper_Result_type_support_data_t _MoveGripper_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_Result_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_Result_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_Result_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_Result__get_type_hash,
  &ur5_test__action__MoveGripper_Result__get_type_description,
  &ur5_test__action__MoveGripper_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_Result)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_Feedback_type_support_ids_t;

static const _MoveGripper_Feedback_type_support_ids_t _MoveGripper_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_Feedback_type_support_symbol_names_t _MoveGripper_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_Feedback)),
  }
};

typedef struct _MoveGripper_Feedback_type_support_data_t
{
  void * data[2];
} _MoveGripper_Feedback_type_support_data_t;

static _MoveGripper_Feedback_type_support_data_t _MoveGripper_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_Feedback_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_Feedback__get_type_hash,
  &ur5_test__action__MoveGripper_Feedback__get_type_description,
  &ur5_test__action__MoveGripper_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_Feedback)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_SendGoal_Request_type_support_ids_t;

static const _MoveGripper_SendGoal_Request_type_support_ids_t _MoveGripper_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_SendGoal_Request_type_support_symbol_names_t _MoveGripper_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_SendGoal_Request)),
  }
};

typedef struct _MoveGripper_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _MoveGripper_SendGoal_Request_type_support_data_t;

static _MoveGripper_SendGoal_Request_type_support_data_t _MoveGripper_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_SendGoal_Request_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_SendGoal_Request__get_type_hash,
  &ur5_test__action__MoveGripper_SendGoal_Request__get_type_description,
  &ur5_test__action__MoveGripper_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_SendGoal_Request)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_SendGoal_Response_type_support_ids_t;

static const _MoveGripper_SendGoal_Response_type_support_ids_t _MoveGripper_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_SendGoal_Response_type_support_symbol_names_t _MoveGripper_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_SendGoal_Response)),
  }
};

typedef struct _MoveGripper_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _MoveGripper_SendGoal_Response_type_support_data_t;

static _MoveGripper_SendGoal_Response_type_support_data_t _MoveGripper_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_SendGoal_Response_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_SendGoal_Response__get_type_hash,
  &ur5_test__action__MoveGripper_SendGoal_Response__get_type_description,
  &ur5_test__action__MoveGripper_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_SendGoal_Response)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_SendGoal_Event_type_support_ids_t;

static const _MoveGripper_SendGoal_Event_type_support_ids_t _MoveGripper_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_SendGoal_Event_type_support_symbol_names_t _MoveGripper_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_SendGoal_Event)),
  }
};

typedef struct _MoveGripper_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _MoveGripper_SendGoal_Event_type_support_data_t;

static _MoveGripper_SendGoal_Event_type_support_data_t _MoveGripper_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_SendGoal_Event_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_SendGoal_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_SendGoal_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_SendGoal_Event__get_type_hash,
  &ur5_test__action__MoveGripper_SendGoal_Event__get_type_description,
  &ur5_test__action__MoveGripper_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_SendGoal_Event)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _MoveGripper_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_SendGoal_type_support_ids_t;

static const _MoveGripper_SendGoal_type_support_ids_t _MoveGripper_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_SendGoal_type_support_symbol_names_t _MoveGripper_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_SendGoal)),
  }
};

typedef struct _MoveGripper_SendGoal_type_support_data_t
{
  void * data[2];
} _MoveGripper_SendGoal_type_support_data_t;

static _MoveGripper_SendGoal_type_support_data_t _MoveGripper_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_SendGoal_service_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveGripper_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &MoveGripper_SendGoal_Request_message_type_support_handle,
  &MoveGripper_SendGoal_Response_message_type_support_handle,
  &MoveGripper_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ur5_test,
    action,
    MoveGripper_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ur5_test,
    action,
    MoveGripper_SendGoal
  ),
  &ur5_test__action__MoveGripper_SendGoal__get_type_hash,
  &ur5_test__action__MoveGripper_SendGoal__get_type_description,
  &ur5_test__action__MoveGripper_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_SendGoal)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_GetResult_Request_type_support_ids_t;

static const _MoveGripper_GetResult_Request_type_support_ids_t _MoveGripper_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_GetResult_Request_type_support_symbol_names_t _MoveGripper_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_GetResult_Request)),
  }
};

typedef struct _MoveGripper_GetResult_Request_type_support_data_t
{
  void * data[2];
} _MoveGripper_GetResult_Request_type_support_data_t;

static _MoveGripper_GetResult_Request_type_support_data_t _MoveGripper_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_GetResult_Request_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_GetResult_Request__get_type_hash,
  &ur5_test__action__MoveGripper_GetResult_Request__get_type_description,
  &ur5_test__action__MoveGripper_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_GetResult_Request)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_GetResult_Response_type_support_ids_t;

static const _MoveGripper_GetResult_Response_type_support_ids_t _MoveGripper_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_GetResult_Response_type_support_symbol_names_t _MoveGripper_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_GetResult_Response)),
  }
};

typedef struct _MoveGripper_GetResult_Response_type_support_data_t
{
  void * data[2];
} _MoveGripper_GetResult_Response_type_support_data_t;

static _MoveGripper_GetResult_Response_type_support_data_t _MoveGripper_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_GetResult_Response_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_GetResult_Response__get_type_hash,
  &ur5_test__action__MoveGripper_GetResult_Response__get_type_description,
  &ur5_test__action__MoveGripper_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_GetResult_Response)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_GetResult_Event_type_support_ids_t;

static const _MoveGripper_GetResult_Event_type_support_ids_t _MoveGripper_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_GetResult_Event_type_support_symbol_names_t _MoveGripper_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_GetResult_Event)),
  }
};

typedef struct _MoveGripper_GetResult_Event_type_support_data_t
{
  void * data[2];
} _MoveGripper_GetResult_Event_type_support_data_t;

static _MoveGripper_GetResult_Event_type_support_data_t _MoveGripper_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_GetResult_Event_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_GetResult_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_GetResult_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_GetResult_Event__get_type_hash,
  &ur5_test__action__MoveGripper_GetResult_Event__get_type_description,
  &ur5_test__action__MoveGripper_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_GetResult_Event)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "service_msgs/msg/service_event_info.h"
// already included above
// #include "builtin_interfaces/msg/time.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _MoveGripper_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_GetResult_type_support_ids_t;

static const _MoveGripper_GetResult_type_support_ids_t _MoveGripper_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_GetResult_type_support_symbol_names_t _MoveGripper_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_GetResult)),
  }
};

typedef struct _MoveGripper_GetResult_type_support_data_t
{
  void * data[2];
} _MoveGripper_GetResult_type_support_data_t;

static _MoveGripper_GetResult_type_support_data_t _MoveGripper_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_GetResult_service_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveGripper_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &MoveGripper_GetResult_Request_message_type_support_handle,
  &MoveGripper_GetResult_Response_message_type_support_handle,
  &MoveGripper_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ur5_test,
    action,
    MoveGripper_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ur5_test,
    action,
    MoveGripper_GetResult
  ),
  &ur5_test__action__MoveGripper_GetResult__get_type_hash,
  &ur5_test__action__MoveGripper_GetResult__get_type_description,
  &ur5_test__action__MoveGripper_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_GetResult)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace ur5_test
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveGripper_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveGripper_FeedbackMessage_type_support_ids_t;

static const _MoveGripper_FeedbackMessage_type_support_ids_t _MoveGripper_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveGripper_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveGripper_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveGripper_FeedbackMessage_type_support_symbol_names_t _MoveGripper_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ur5_test, action, MoveGripper_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ur5_test, action, MoveGripper_FeedbackMessage)),
  }
};

typedef struct _MoveGripper_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _MoveGripper_FeedbackMessage_type_support_data_t;

static _MoveGripper_FeedbackMessage_type_support_data_t _MoveGripper_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveGripper_FeedbackMessage_message_typesupport_map = {
  2,
  "ur5_test",
  &_MoveGripper_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_MoveGripper_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_MoveGripper_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveGripper_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveGripper_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &ur5_test__action__MoveGripper_FeedbackMessage__get_type_hash,
  &ur5_test__action__MoveGripper_FeedbackMessage__get_type_description,
  &ur5_test__action__MoveGripper_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace ur5_test

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, ur5_test, action, MoveGripper_FeedbackMessage)() {
  return &::ur5_test::action::rosidl_typesupport_c::MoveGripper_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "ur5_test/action/move_gripper.h"
// already included above
// #include "ur5_test/action/detail/move_gripper__type_support.h"

static rosidl_action_type_support_t _ur5_test__action__MoveGripper__typesupport_c = {
  NULL, NULL, NULL, NULL, NULL,
  &ur5_test__action__MoveGripper__get_type_hash,
  &ur5_test__action__MoveGripper__get_type_description,
  &ur5_test__action__MoveGripper__get_type_description_sources,
};

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, ur5_test, action, MoveGripper)()
{
  // Thread-safe by always writing the same values to the static struct
  _ur5_test__action__MoveGripper__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, ur5_test, action, MoveGripper_SendGoal)();
  _ur5_test__action__MoveGripper__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, ur5_test, action, MoveGripper_GetResult)();
  _ur5_test__action__MoveGripper__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _ur5_test__action__MoveGripper__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, ur5_test, action, MoveGripper_FeedbackMessage)();
  _ur5_test__action__MoveGripper__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_ur5_test__action__MoveGripper__typesupport_c;
}

#ifdef __cplusplus
}
#endif
