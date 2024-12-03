#pragma once
#include <string>

#include "pose.h"
#include "pose_handler.h"

namespace car {

class Executor {
   protected:
	Pose pose;

   public:
	static Executor* NewExecutor(const Pose& pose = {false, 0, 0, 'N'});

	Executor() = default;
	virtual ~Executor() = default;

	Executor(const Executor&) = delete;
	Executor& operator=(const Executor&) = delete;

   public:
	virtual PoseHandler& Query() noexcept = 0;
	virtual void Execute(const std::string& command) noexcept = 0;
};

class ExecutorImpl : public Executor {
   public:
	static ExecutorImpl* NewExecutor(const Pose& pose = {false, false, 0, 0,
														 'N'});
	ExecutorImpl(const Pose& poseIn) : poseHandler(poseIn) {}

	PoseHandler& Query() noexcept;
	void Execute(const std::string& command) noexcept;

   private:
	PoseHandler poseHandler;
};

}  // namespace car
