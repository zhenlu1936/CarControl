#pragma once
#include <string>

#include "pose.h"
#include "pose_handler.h"

#define TYPE_NORMAL 'n'
#define TYPE_SPORTS 's'
#define TYPE_BUS 'b'

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
	virtual PoseHandler& GetPoseHandler() noexcept = 0;
	virtual void Execute(const std::string& command) noexcept = 0;
};

class ExecutorImpl : public Executor {
   public:
	static ExecutorImpl* NewExecutor(const Pose& pose = {false, false, 0, 0,
														 'N'},
									 const char carType = TYPE_NORMAL);
	ExecutorImpl(const Pose& poseIn) : poseHandler(poseIn) {}
	ExecutorImpl(const Pose& poseIn, const char carTypeIn)
		: poseHandler(poseIn), carType(carTypeIn) {}

	PoseHandler& GetPoseHandler() noexcept;
	char GetCarType() const noexcept;
	void Execute(const std::string& command) noexcept;

   private:
	PoseHandler poseHandler;
	char carType;
};

}  // namespace car
