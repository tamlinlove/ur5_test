// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ur5_test:action/MoveGripper.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ur5_test/action/move_gripper.h"


#ifndef UR5_TEST__ACTION__DETAIL__MOVE_GRIPPER__STRUCT_H_
#define UR5_TEST__ACTION__DETAIL__MOVE_GRIPPER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_Goal
{
  double x;
  double y;
  double z;
  bool use_default_z;
} ur5_test__action__MoveGripper_Goal;

// Struct for a sequence of ur5_test__action__MoveGripper_Goal.
typedef struct ur5_test__action__MoveGripper_Goal__Sequence
{
  ur5_test__action__MoveGripper_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_Result
{
  bool success;
  rosidl_runtime_c__String message;
} ur5_test__action__MoveGripper_Result;

// Struct for a sequence of ur5_test__action__MoveGripper_Result.
typedef struct ur5_test__action__MoveGripper_Result__Sequence
{
  ur5_test__action__MoveGripper_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_Feedback
{
  rosidl_runtime_c__String status;
} ur5_test__action__MoveGripper_Feedback;

// Struct for a sequence of ur5_test__action__MoveGripper_Feedback.
typedef struct ur5_test__action__MoveGripper_Feedback__Sequence
{
  ur5_test__action__MoveGripper_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "ur5_test/action/detail/move_gripper__struct.h"

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  ur5_test__action__MoveGripper_Goal goal;
} ur5_test__action__MoveGripper_SendGoal_Request;

// Struct for a sequence of ur5_test__action__MoveGripper_SendGoal_Request.
typedef struct ur5_test__action__MoveGripper_SendGoal_Request__Sequence
{
  ur5_test__action__MoveGripper_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} ur5_test__action__MoveGripper_SendGoal_Response;

// Struct for a sequence of ur5_test__action__MoveGripper_SendGoal_Response.
typedef struct ur5_test__action__MoveGripper_SendGoal_Response__Sequence
{
  ur5_test__action__MoveGripper_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ur5_test__action__MoveGripper_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ur5_test__action__MoveGripper_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ur5_test__action__MoveGripper_SendGoal_Request__Sequence request;
  ur5_test__action__MoveGripper_SendGoal_Response__Sequence response;
} ur5_test__action__MoveGripper_SendGoal_Event;

// Struct for a sequence of ur5_test__action__MoveGripper_SendGoal_Event.
typedef struct ur5_test__action__MoveGripper_SendGoal_Event__Sequence
{
  ur5_test__action__MoveGripper_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} ur5_test__action__MoveGripper_GetResult_Request;

// Struct for a sequence of ur5_test__action__MoveGripper_GetResult_Request.
typedef struct ur5_test__action__MoveGripper_GetResult_Request__Sequence
{
  ur5_test__action__MoveGripper_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_GetResult_Response
{
  int8_t status;
  ur5_test__action__MoveGripper_Result result;
} ur5_test__action__MoveGripper_GetResult_Response;

// Struct for a sequence of ur5_test__action__MoveGripper_GetResult_Response.
typedef struct ur5_test__action__MoveGripper_GetResult_Response__Sequence
{
  ur5_test__action__MoveGripper_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  ur5_test__action__MoveGripper_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  ur5_test__action__MoveGripper_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  ur5_test__action__MoveGripper_GetResult_Request__Sequence request;
  ur5_test__action__MoveGripper_GetResult_Response__Sequence response;
} ur5_test__action__MoveGripper_GetResult_Event;

// Struct for a sequence of ur5_test__action__MoveGripper_GetResult_Event.
typedef struct ur5_test__action__MoveGripper_GetResult_Event__Sequence
{
  ur5_test__action__MoveGripper_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "ur5_test/action/detail/move_gripper__struct.h"

/// Struct defined in action/MoveGripper in the package ur5_test.
typedef struct ur5_test__action__MoveGripper_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  ur5_test__action__MoveGripper_Feedback feedback;
} ur5_test__action__MoveGripper_FeedbackMessage;

// Struct for a sequence of ur5_test__action__MoveGripper_FeedbackMessage.
typedef struct ur5_test__action__MoveGripper_FeedbackMessage__Sequence
{
  ur5_test__action__MoveGripper_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur5_test__action__MoveGripper_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UR5_TEST__ACTION__DETAIL__MOVE_GRIPPER__STRUCT_H_
