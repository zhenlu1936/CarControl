#include "pose_handler.h"

namespace car {
class ICommand {
   public:
	virtual ~ICommand() = default;
	virtual void Operate(PoseHandler& poseHandler) const noexcept = 0;
};

class MoveCommand : public ICommand {
   public:
	void Operate(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.Move();
		}
		poseHandler.Move();
	}
};

class TurnLeftCommand : public ICommand {
   public:
	void Operate(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.Move();
		}
		poseHandler.TurnLeft();
	}
};

class TurnRightCommand : public ICommand {
   public:
	void Operate(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.Move();
		}
		poseHandler.TurnRight();
	}
};

class FastCommand : public ICommand {
   public:
	void Operate(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.DisableFast();
		} else
			poseHandler.EnableFast();
	}
};
};