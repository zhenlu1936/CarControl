#include "action_group.h"

namespace car {
using Action = std::function<void(PoseHandler& poseHandler)>;

class ForwardAction final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		poseHandler.MoveForward();
	}
};
class BackwardAction final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		poseHandler.MoveBackward();
	}
};
class TurnLeftAction final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		poseHandler.TurnLeft();
	}
};
class ReverseTurnLeftAction final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		poseHandler.TurnRight();
	}
};
class TurnRightAction final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		poseHandler.TurnRight();
	}
};
class ReverseTurnRightction final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		poseHandler.TurnLeft();
	}
};
class ChangeFastAction final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		poseHandler.ChangeFast();
	}
};
class ChangeReverseAction final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		poseHandler.ChangeReverse();
	}
};
void ActionGroup::PushAction(const ActionType actionType) noexcept {
	actions.push_back(actionType);
};
void ActionGroup::DoAction(PoseHandler& poseHandler) const noexcept {
	static std::vector<Action> actionVec = {
		ForwardAction(),		 BackwardAction(),	   TurnLeftAction(),
		ReverseTurnLeftAction(), TurnRightAction(),	   ReverseTurnRightction(),
		ChangeFastAction(),		 ChangeReverseAction()};
	std::for_each(actions.begin(), actions.end(),
				  [&poseHandler](const ActionType actionType) mutable noexcept {
					  actionVec[static_cast<uint16_t>(actionType)](poseHandler);
				  });
};
}  // namespace car