#include "executor.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "command.hpp"
#include "pose_handler.h"
#include "pose.h"

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

void ExecutorImpl::Execute(const std::string& command) noexcept {
	for (int i = 0; i < command.length(); i++) {
		char oneCommand = command[i];
		std::unique_ptr<ICommand> cmder;
		PoseHandler& poseHandler=this->Query();

		switch (oneCommand) {
			case ('M'): {
				cmder = std::make_unique<MoveCommand>();
				break;
			}
			case ('L'): {
				cmder = std::make_unique<TurnLeftCommand>();
				break;
			}
			case ('R'): {
				cmder = std::make_unique<TurnRightCommand>();
				break;
			}
			case ('F'): {
				cmder = std::make_unique<FastCommand>();
			}
			default:
				break;
		}

		if (cmder != nullptr) {
			cmder->Operate(poseHandler);
		}
	}
}

PoseHandler& ExecutorImpl::Query() noexcept { return poseHandler; }