#include "executor.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace car;

std::map<char, int> car::dir = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
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
				currentPose.x += forward[dir[currentPose.heading]][X];
				currentPose.y += forward[dir[currentPose.heading]][Y];
				break;

			case ('L'):
				currentPose.heading = (currentPose.heading - 1) % DIRECTIONS;
				break;

			case ('R'):
				currentPose.heading = (currentPose.heading + 1) % DIRECTIONS;
				break;

			default:
				break;
		}
	}
}

Pose ExecutorImpl::Query() const noexcept { return pose; };