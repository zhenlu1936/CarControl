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
				currentPose.x +=
					forward[dir_char_to_int[currentPose.heading]][X];
				currentPose.y +=
					forward[dir_char_to_int[currentPose.heading]][Y];
				break;

			case ('L'):
				currentPose.heading =
					dir_int_to_char[(DIRECTIONS +
									 dir_char_to_int[currentPose.heading] - 1) %
									DIRECTIONS];
				break;

			case ('R'):
				currentPose.heading =
					dir_int_to_char[(DIRECTIONS +
									 dir_char_to_int[currentPose.heading] + 1) %
									DIRECTIONS];
				break;

			default:
				break;
		}

		Change(currentPose);
	}
}

Pose ExecutorImpl::Query() const noexcept { return pose; };

void ExecutorImpl::Change(const Pose& poseIn) noexcept {
	pose.heading = poseIn.heading;
	pose.x = poseIn.x;
	pose.y = poseIn.y;
}