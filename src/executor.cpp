#include "executor.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace car;

std::map<char, int> car::dir_char_to_int = {
	{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
std::map<int, char> car::dir_int_to_char = {
	{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};
int car::forward[DIRECTIONS][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

ExecutorImpl* ExecutorImpl::NewExecutor(const Pose& pose) {
	ExecutorImpl* pExecutor = new ExecutorImpl(pose);
	return pExecutor;
}

ExecutorImpl::ExecutorImpl(const Pose& poseIn) {
	pose.heading = poseIn.heading;
	pose.x = poseIn.x;
	pose.y = poseIn.y;
}

void ExecutorImpl::Execute(const std::string& command) noexcept {
	for (int i = 0; i < command.length(); i++) {
		char oneCommand = command[i];
		Pose currentPose = Query();

		switch (oneCommand) {
			case ('M'):
				Move(currentPose);
				break;

			case ('L'):
				TurnLeft(currentPose);
				break;

			case ('R'):
				TurnRight(currentPose);
				break;

			default:
				break;
		}

		ChangeTo(currentPose);
	}
}

Pose ExecutorImpl::Query() const noexcept { return pose; };

void ExecutorImpl::ChangeTo(const Pose& poseIn) noexcept {
	pose.heading = poseIn.heading;
	pose.x = poseIn.x;
	pose.y = poseIn.y;
}

void ExecutorImpl::Move(Pose& currentPose) noexcept {
	currentPose.x += forward[dir_char_to_int[currentPose.heading]][X];
	currentPose.y += forward[dir_char_to_int[currentPose.heading]][Y];
}

void ExecutorImpl::TurnLeft(Pose& currentPose) noexcept {
	currentPose.heading = dir_int_to_char
		[(DIRECTIONS + dir_char_to_int[currentPose.heading] - 1) % DIRECTIONS];
}

void ExecutorImpl::TurnRight(Pose& currentPose) noexcept {
	currentPose.heading = dir_int_to_char
		[(DIRECTIONS + dir_char_to_int[currentPose.heading] + 1) % DIRECTIONS];
}