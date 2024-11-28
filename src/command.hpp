#include <functional>

#include "pose_handler.h"

namespace car {

class MoveCommand final {
   public:
	const std::function<void(PoseHandler& PoseHandler)> operate =
		[](PoseHandler& poseHandler) noexcept {
			if (poseHandler.IsFast()) {
				poseHandler.Move();
			}
			poseHandler.Move();
		};
};

class TurnLeftCommand final {
   public:
	const std::function<void(PoseHandler& PoseHandler)> operate =
		[](PoseHandler& poseHandler) noexcept {
			if (poseHandler.IsFast()) {
				poseHandler.Move();
			}
			poseHandler.TurnLeft();
		};
};

class TurnRightCommand final {
   public:
	const std::function<void(PoseHandler& PoseHandler)> operate =
		[](PoseHandler& poseHandler) noexcept {
			if (poseHandler.IsFast()) {
				poseHandler.Move();
			}
			poseHandler.TurnRight();
		};
};

class FastCommand final {
   public:
	const std::function<void(PoseHandler& PoseHandler)> operate =
		[](PoseHandler& poseHandler) noexcept {
			if (poseHandler.IsFast()) {
				poseHandler.DisableFast();
			} else
				poseHandler.EnableFast();
		};
};
};	// namespace car