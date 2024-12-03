#include "pose_handler.h"

namespace car {
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose) {};

PoseHandler::PoseHandler(const PoseHandler& poseHandler) noexcept
	: pose(poseHandler.Query()) {};

void PoseHandler::ChangeFast() noexcept { pose.fastStatus = !pose.fastStatus; }

void PoseHandler::ChangeBack() noexcept { pose.backStatus = !pose.backStatus; }

void PoseHandler::MoveForward() noexcept {
	pose.point += pose.direction.Move();
}

void PoseHandler::MoveBackward() noexcept {
	pose.point -= pose.direction.Move();
}

void PoseHandler::TurnLeft() noexcept { pose.direction.TurnLeft(); }

void PoseHandler::TurnRight() noexcept { pose.direction.TurnRight(); }

Pose PoseHandler::Query() const noexcept { return pose; };

bool PoseHandler::IsFast() const noexcept { return pose.fastStatus; };

bool PoseHandler::IsBack() const noexcept { return pose.backStatus; };

bool operator==(const PoseHandler& lhs, const PoseHandler& rhs) noexcept {
	return lhs.Query() == rhs.Query();
}
}  // namespace car