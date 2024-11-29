#include <functional>

#include "pose_handler.h"

namespace car {

class MoveCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.Move();
		}
		poseHandler.Move();
	};
};

class TurnLeftCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.Move();
		}
		poseHandler.TurnLeft();
	};
};

class TurnRightCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.Move();
		}
		poseHandler.TurnRight();
	};
};

class FastCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.DisableFast();
		} else
			poseHandler.EnableFast();
	};
};
};	// namespace car