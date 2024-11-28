#pragma once
#include "pose.h"

namespace car {
class PoseHandler final {
   public:
	PoseHandler(const Pose& pose) noexcept;
	PoseHandler(const PoseHandler&) noexcept;
	PoseHandler(bool fastIn, int xIn, int yIn, char headingIn)
		: pose(fastIn, xIn, yIn, headingIn) {}

   public:
	void Move(void) noexcept;
	void TurnLeft(void) noexcept;
	void TurnRight(void) noexcept;
	void EnableFast(void) noexcept;
	void DisableFast(void) noexcept;

	Pose Query(void) const noexcept;
	bool IsFast(void) const noexcept;

   private:
	Pose pose;
};

bool operator==(const PoseHandler& lhs, const PoseHandler& rhs) noexcept;
}  // namespace car