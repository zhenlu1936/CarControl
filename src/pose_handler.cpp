#include "pose_handler.h"

namespace car {
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose) {};

PoseHandler::PoseHandler(const PoseHandler& poseHandler) noexcept
	: pose(poseHandler.Query()) {};

void PoseHandler::EnableFast() noexcept { pose.fastStatus = true; }

void PoseHandler::DisableFast() noexcept { pose.fastStatus = false; }

void PoseHandler::EnableBack() noexcept { pose.backStatus = true; }

void PoseHandler::DisableBack() noexcept { pose.backStatus = false; }

void PoseHandler::MoveForward() noexcept {
	pose.x += forward[dir_char_to_int[pose.heading]][X];
	pose.y += forward[dir_char_to_int[pose.heading]][Y];
}

void PoseHandler::MoveBackwards() noexcept {
	pose.x -= forward[dir_char_to_int[pose.heading]][X];
	pose.y -= forward[dir_char_to_int[pose.heading]][Y];
}

void PoseHandler::TurnLeft() noexcept {
	pose.heading =
		dir_int_to_char[(DIRECTIONS + dir_char_to_int[pose.heading] - 1) %
						DIRECTIONS];
}

void PoseHandler::TurnRight() noexcept {
	pose.heading =
		dir_int_to_char[(DIRECTIONS + dir_char_to_int[pose.heading] + 1) %
						DIRECTIONS];
}

Pose PoseHandler::Query() const noexcept { return pose; };

bool PoseHandler::IsFast() const noexcept { return pose.fastStatus; };

bool PoseHandler::IsBack() const noexcept { return pose.backStatus; };

bool operator==(const PoseHandler& lhs, const PoseHandler& rhs) noexcept {
	return lhs.Query() == rhs.Query();
}
}  // namespace car