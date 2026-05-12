// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ur5_test:action/MoveGripper.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ur5_test/action/move_gripper.hpp"


#ifndef UR5_TEST__ACTION__DETAIL__MOVE_GRIPPER__BUILDER_HPP_
#define UR5_TEST__ACTION__DETAIL__MOVE_GRIPPER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ur5_test/action/detail/move_gripper__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_Goal_use_default_z
{
public:
  explicit Init_MoveGripper_Goal_use_default_z(::ur5_test::action::MoveGripper_Goal & msg)
  : msg_(msg)
  {}
  ::ur5_test::action::MoveGripper_Goal use_default_z(::ur5_test::action::MoveGripper_Goal::_use_default_z_type arg)
  {
    msg_.use_default_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_Goal msg_;
};

class Init_MoveGripper_Goal_z
{
public:
  explicit Init_MoveGripper_Goal_z(::ur5_test::action::MoveGripper_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveGripper_Goal_use_default_z z(::ur5_test::action::MoveGripper_Goal::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_MoveGripper_Goal_use_default_z(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_Goal msg_;
};

class Init_MoveGripper_Goal_y
{
public:
  explicit Init_MoveGripper_Goal_y(::ur5_test::action::MoveGripper_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveGripper_Goal_z y(::ur5_test::action::MoveGripper_Goal::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_MoveGripper_Goal_z(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_Goal msg_;
};

class Init_MoveGripper_Goal_x
{
public:
  Init_MoveGripper_Goal_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripper_Goal_y x(::ur5_test::action::MoveGripper_Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MoveGripper_Goal_y(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_Goal>()
{
  return ur5_test::action::builder::Init_MoveGripper_Goal_x();
}

}  // namespace ur5_test


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_Result_message
{
public:
  explicit Init_MoveGripper_Result_message(::ur5_test::action::MoveGripper_Result & msg)
  : msg_(msg)
  {}
  ::ur5_test::action::MoveGripper_Result message(::ur5_test::action::MoveGripper_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_Result msg_;
};

class Init_MoveGripper_Result_success
{
public:
  Init_MoveGripper_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripper_Result_message success(::ur5_test::action::MoveGripper_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveGripper_Result_message(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_Result>()
{
  return ur5_test::action::builder::Init_MoveGripper_Result_success();
}

}  // namespace ur5_test


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_Feedback_status
{
public:
  Init_MoveGripper_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ur5_test::action::MoveGripper_Feedback status(::ur5_test::action::MoveGripper_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_Feedback>()
{
  return ur5_test::action::builder::Init_MoveGripper_Feedback_status();
}

}  // namespace ur5_test


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_SendGoal_Request_goal
{
public:
  explicit Init_MoveGripper_SendGoal_Request_goal(::ur5_test::action::MoveGripper_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::ur5_test::action::MoveGripper_SendGoal_Request goal(::ur5_test::action::MoveGripper_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_SendGoal_Request msg_;
};

class Init_MoveGripper_SendGoal_Request_goal_id
{
public:
  Init_MoveGripper_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripper_SendGoal_Request_goal goal_id(::ur5_test::action::MoveGripper_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveGripper_SendGoal_Request_goal(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_SendGoal_Request>()
{
  return ur5_test::action::builder::Init_MoveGripper_SendGoal_Request_goal_id();
}

}  // namespace ur5_test


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_SendGoal_Response_stamp
{
public:
  explicit Init_MoveGripper_SendGoal_Response_stamp(::ur5_test::action::MoveGripper_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::ur5_test::action::MoveGripper_SendGoal_Response stamp(::ur5_test::action::MoveGripper_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_SendGoal_Response msg_;
};

class Init_MoveGripper_SendGoal_Response_accepted
{
public:
  Init_MoveGripper_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripper_SendGoal_Response_stamp accepted(::ur5_test::action::MoveGripper_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveGripper_SendGoal_Response_stamp(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_SendGoal_Response>()
{
  return ur5_test::action::builder::Init_MoveGripper_SendGoal_Response_accepted();
}

}  // namespace ur5_test


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_SendGoal_Event_response
{
public:
  explicit Init_MoveGripper_SendGoal_Event_response(::ur5_test::action::MoveGripper_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::ur5_test::action::MoveGripper_SendGoal_Event response(::ur5_test::action::MoveGripper_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_SendGoal_Event msg_;
};

class Init_MoveGripper_SendGoal_Event_request
{
public:
  explicit Init_MoveGripper_SendGoal_Event_request(::ur5_test::action::MoveGripper_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_MoveGripper_SendGoal_Event_response request(::ur5_test::action::MoveGripper_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveGripper_SendGoal_Event_response(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_SendGoal_Event msg_;
};

class Init_MoveGripper_SendGoal_Event_info
{
public:
  Init_MoveGripper_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripper_SendGoal_Event_request info(::ur5_test::action::MoveGripper_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveGripper_SendGoal_Event_request(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_SendGoal_Event>()
{
  return ur5_test::action::builder::Init_MoveGripper_SendGoal_Event_info();
}

}  // namespace ur5_test


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_GetResult_Request_goal_id
{
public:
  Init_MoveGripper_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ur5_test::action::MoveGripper_GetResult_Request goal_id(::ur5_test::action::MoveGripper_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_GetResult_Request>()
{
  return ur5_test::action::builder::Init_MoveGripper_GetResult_Request_goal_id();
}

}  // namespace ur5_test


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_GetResult_Response_result
{
public:
  explicit Init_MoveGripper_GetResult_Response_result(::ur5_test::action::MoveGripper_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::ur5_test::action::MoveGripper_GetResult_Response result(::ur5_test::action::MoveGripper_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_GetResult_Response msg_;
};

class Init_MoveGripper_GetResult_Response_status
{
public:
  Init_MoveGripper_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripper_GetResult_Response_result status(::ur5_test::action::MoveGripper_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveGripper_GetResult_Response_result(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_GetResult_Response>()
{
  return ur5_test::action::builder::Init_MoveGripper_GetResult_Response_status();
}

}  // namespace ur5_test


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_GetResult_Event_response
{
public:
  explicit Init_MoveGripper_GetResult_Event_response(::ur5_test::action::MoveGripper_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::ur5_test::action::MoveGripper_GetResult_Event response(::ur5_test::action::MoveGripper_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_GetResult_Event msg_;
};

class Init_MoveGripper_GetResult_Event_request
{
public:
  explicit Init_MoveGripper_GetResult_Event_request(::ur5_test::action::MoveGripper_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_MoveGripper_GetResult_Event_response request(::ur5_test::action::MoveGripper_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveGripper_GetResult_Event_response(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_GetResult_Event msg_;
};

class Init_MoveGripper_GetResult_Event_info
{
public:
  Init_MoveGripper_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripper_GetResult_Event_request info(::ur5_test::action::MoveGripper_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveGripper_GetResult_Event_request(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_GetResult_Event>()
{
  return ur5_test::action::builder::Init_MoveGripper_GetResult_Event_info();
}

}  // namespace ur5_test


namespace ur5_test
{

namespace action
{

namespace builder
{

class Init_MoveGripper_FeedbackMessage_feedback
{
public:
  explicit Init_MoveGripper_FeedbackMessage_feedback(::ur5_test::action::MoveGripper_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::ur5_test::action::MoveGripper_FeedbackMessage feedback(::ur5_test::action::MoveGripper_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_FeedbackMessage msg_;
};

class Init_MoveGripper_FeedbackMessage_goal_id
{
public:
  Init_MoveGripper_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveGripper_FeedbackMessage_feedback goal_id(::ur5_test::action::MoveGripper_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveGripper_FeedbackMessage_feedback(msg_);
  }

private:
  ::ur5_test::action::MoveGripper_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::ur5_test::action::MoveGripper_FeedbackMessage>()
{
  return ur5_test::action::builder::Init_MoveGripper_FeedbackMessage_goal_id();
}

}  // namespace ur5_test

#endif  // UR5_TEST__ACTION__DETAIL__MOVE_GRIPPER__BUILDER_HPP_
