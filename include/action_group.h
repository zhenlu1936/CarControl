#pragma once

#include <list>

#include "pose_handler.h"

namespace car {
enum class ActionType : uint16_t {
	FORWARD_1_STEP_ACTION = 0,
	BACKWARD_1_STEP_ACTION,
	TURN_LEFT_ACTION,
	REVERSE_TURN_LEFT_ACTION,
	TURN_RIGHT_ACTION,
	REVERSE_TURN_RIGHT_ACTION,
	CHANGE_FAST_ACTION,
	CHANGE_REVERSE_ACTION,
};

class ActionGroup final {
   public:
	ActionGroup(void) = default;
	explicit ActionGroup(const std::list<ActionType>& actionsIn) noexcept
		: actions(actionsIn) {}
	~ActionGroup() = default;

	void PushAction(const ActionType actionType) noexcept;
	void DoAction(PoseHandler& poseHandler) const noexcept;

   private:
	std::list<ActionType> actions;
};
}  // namespace car