#include <functional>

#include "pose_handler.h"
#include "action_group.h"

namespace car {

class MoveCommand final {
   public:
	ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
		ActionGroup actionGroup;
		if (!poseHandler.IsReverse() && !poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
		}
		if (!poseHandler.IsReverse() && poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
			actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
		}
		if (poseHandler.IsReverse() && !poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::BACKWARD_1_STEP_ACTION);
		}
		if (poseHandler.IsReverse() && poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::BACKWARD_1_STEP_ACTION);
			actionGroup.PushAction(ActionType::BACKWARD_1_STEP_ACTION);
		}
		return actionGroup;
	};
};

class TurnLeftCommand final {
   public:
	ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
		ActionGroup actionGroup;
		if (!poseHandler.IsReverse() && !poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::TURN_LEFT_ACTION);
		}
		if (!poseHandler.IsReverse() && poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
			actionGroup.PushAction(ActionType::TURN_LEFT_ACTION);
		}
		if (poseHandler.IsReverse() && !poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::REVERSE_TURN_LEFT_ACTION);
		}
		if (poseHandler.IsReverse() && poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::BACKWARD_1_STEP_ACTION);
			actionGroup.PushAction(ActionType::REVERSE_TURN_LEFT_ACTION);
		}
		return actionGroup;
	};
};

class TurnRightCommand final {
   public:
	ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
		ActionGroup actionGroup;
		if (!poseHandler.IsReverse() && !poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::TURN_RIGHT_ACTION);
		}
		if (!poseHandler.IsReverse() && poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
			actionGroup.PushAction(ActionType::TURN_RIGHT_ACTION);
		}
		if (poseHandler.IsReverse() && !poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::REVERSE_TURN_RIGHT_ACTION);
		}
		if (poseHandler.IsReverse() && poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::BACKWARD_1_STEP_ACTION);
			actionGroup.PushAction(ActionType::REVERSE_TURN_RIGHT_ACTION);
		}
		return actionGroup;
	};
};

class TurnRoundCommand final {
   public:
	ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
		ActionGroup actionGroup;
		if(poseHandler.IsReverse()){
			return actionGroup;
		}
		if (!poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::TURN_LEFT_ACTION);
			actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
			actionGroup.PushAction(ActionType::TURN_LEFT_ACTION);
		}
		if (poseHandler.IsFast()) {
			actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
			actionGroup.PushAction(ActionType::TURN_LEFT_ACTION);
			actionGroup.PushAction(ActionType::FORWARD_1_STEP_ACTION);
			actionGroup.PushAction(ActionType::TURN_LEFT_ACTION);
		}
		return actionGroup;
	};
};

class FastCommand final {
   public:
	ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
		ActionGroup actionGroup;
		actionGroup.PushAction(ActionType::CHANGE_FAST_ACTION);
		return actionGroup;
	};
};

class BackCommand final {
   public:
	ActionGroup operator()(PoseHandler& poseHandler) const noexcept {
		ActionGroup actionGroup;
		actionGroup.PushAction(ActionType::CHANGE_REVERSE_ACTION);
		return actionGroup;
	};
};
};	// namespace car