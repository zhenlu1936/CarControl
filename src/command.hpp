#include <functional>

#include "pose_handler.h"

namespace car {

class MoveForwardCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.MoveForward();
		}
		poseHandler.MoveForward();
	};
};

class TurnLeftCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.MoveForward();
		}
		poseHandler.TurnLeft();
	};
};

class TurnRightCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsFast()) {
			poseHandler.MoveForward();
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