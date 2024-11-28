#include "executor.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "command.hpp"
#include "pose.h"
#include "pose_handler.h"

using namespace car;

std::map<char, int> car::dir_char_to_int = {
	{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
std::map<int, char> car::dir_int_to_char = {
	{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};
int car::forward[DIRECTIONS][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
std::map<char, std::function<void(PoseHandler& poseHandler)>> cmderMap;

ExecutorImpl* ExecutorImpl::NewExecutor(const Pose& pose) {
	ExecutorImpl* pExecutor = new ExecutorImpl(pose);
	return pExecutor;
}

void ExecutorImpl::Execute(const std::string& command) noexcept {
	InitalizeCmder();

	for (char oneCommand : command) {
		PoseHandler& poseHandler = this->Query();

		if (oneCommand) {
			cmderMap[oneCommand](poseHandler);
		}
	}
}

PoseHandler& ExecutorImpl::Query() noexcept { return poseHandler; }

void ExecutorImpl::InitalizeCmder() noexcept {
	MoveCommand moveCommand;
	cmderMap.emplace('M', moveCommand.operate);
	TurnLeftCommand turnLeftCommand;
	cmderMap.emplace('L', turnLeftCommand.operate);
	TurnRightCommand turnRightCommand;
	cmderMap.emplace('R', turnRightCommand.operate);
	FastCommand fastCommand;
	cmderMap.emplace('F', fastCommand.operate);
}