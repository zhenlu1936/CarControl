#include "executor.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "cmder_factory.hpp"
#include "pose.h"
#include "pose_handler.h"
#include "singleton.h"

using namespace car;

ExecutorImpl* ExecutorImpl::NewExecutor(const Pose& pose) {
	ExecutorImpl* pExecutor = new ExecutorImpl(pose);
	return pExecutor;
}

void ExecutorImpl::Execute(const std::string& commands) noexcept {
	std::string parsedCommands =
		Singleton<CmderFactory>::instance().ParseCommandString(commands);
	const auto cmders = Singleton<CmderFactory>::instance().GetCmders(parsedCommands);
	std::for_each(cmders.begin(), cmders.end(), [this](const Cmder& cmder) {
		cmder(poseHandler).DoAction(poseHandler);
	});
}

PoseHandler& ExecutorImpl::Query() noexcept { return poseHandler; }
