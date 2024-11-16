#include "executor.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace car;

ExecutorImpl* ExecutorImpl::NewExecutor(const Pose& pose) {
	ExecutorImpl* pExecutor = new ExecutorImpl(pose);
	return pExecutor;
}

ExecutorImpl::ExecutorImpl(const Pose& poseIn) {
	pose.heading = poseIn.heading;
	pose.x = poseIn.x;
	pose.y = poseIn.y;
}

void ExecutorImpl::Execute(const std::string& command) {
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

Pose ExecutorImpl::Query() const { return pose; };