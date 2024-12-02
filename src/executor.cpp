#include "executor.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "cmder_factory.hpp"
#include "pose.h"
#include "pose_handler.h"
#include "singleton.h"

using namespace car;

std::unordered_map<char, int> car::dir_char_to_int = {
	{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
std::unordered_map<int, char> car::dir_int_to_char = {
	{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};
int car::forward[DIRECTIONS][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

ExecutorImpl* ExecutorImpl::NewExecutor(const Pose& pose) {
	ExecutorImpl* pExecutor = new ExecutorImpl(pose);
	return pExecutor;
}

void ExecutorImpl::Execute(const std::string& commands) noexcept {
	const auto cmders = Singleton<CmderFactory>::instance().GetCmders(commands);
	std::for_each(cmders.begin(), cmders.end(),
				  [this](const Cmder& cmder) { cmder(poseHandler); });
}

PoseHandler& ExecutorImpl::Query() noexcept { return poseHandler; }
