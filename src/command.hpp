#include <functional>

#include "pose_handler.h"

namespace car {

class MoveCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (!poseHandler.IsBack() && !poseHandler.IsFast()) {
			poseHandler.MoveForward();
			return;
		}
		if (!poseHandler.IsBack() && poseHandler.IsFast()) {
			poseHandler.MoveForward();
			poseHandler.MoveForward();
			return;
		}
		if (poseHandler.IsBack() && !poseHandler.IsFast()) {
			poseHandler.MoveBackwards();
			return;
		}
		if (poseHandler.IsBack() && poseHandler.IsFast()) {
			poseHandler.MoveBackwards();
			poseHandler.MoveBackwards();
			return;
		}
	};
};

class TurnLeftCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (!poseHandler.IsBack() && !poseHandler.IsFast()) {
			poseHandler.TurnLeft();
			return;
		}
		if (!poseHandler.IsBack() && poseHandler.IsFast()) {
			poseHandler.MoveForward();
			poseHandler.TurnLeft();
			return;
		}
		if (poseHandler.IsBack() && !poseHandler.IsFast()) {
			poseHandler.TurnRight();
			return;
		}
		if (poseHandler.IsBack() && poseHandler.IsFast()) {
			poseHandler.MoveBackwards();
			poseHandler.TurnRight();
			return;
		}
	};
};

class TurnRightCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (!poseHandler.IsBack() && !poseHandler.IsFast()) {
			poseHandler.TurnRight();
			return;
		}
		if (!poseHandler.IsBack() && poseHandler.IsFast()) {
			poseHandler.MoveForward();
			poseHandler.TurnRight();
			return;
		}
		if (poseHandler.IsBack() && !poseHandler.IsFast()) {
			poseHandler.TurnLeft();
			return;
		}
		if (poseHandler.IsBack() && poseHandler.IsFast()) {
			poseHandler.MoveBackwards();
			poseHandler.TurnLeft();
			return;
		}
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

class BackCommand final {
   public:
	void operator()(PoseHandler& poseHandler) const noexcept {
		if (poseHandler.IsBack()) {
			poseHandler.DisableBack();
		} else
			poseHandler.EnableBack();
	};
};
};	// namespace car