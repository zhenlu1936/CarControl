#pragma once
#include <map>
#include <string>

#include "pose.h"
#include "pose_handler.h"

#define DIRECTIONS 4
#define X 0
#define Y 1

namespace car {

extern std::map<char, int> dir_char_to_int;
extern std::map<int, char> dir_int_to_char;
extern int forward[DIRECTIONS][2];

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
	static ExecutorImpl* NewExecutor(const Pose& pose = {false, 0, 0, 'N'});
	ExecutorImpl(const Pose& poseIn) : poseHandler(poseIn) {}

	PoseHandler& Query() noexcept;
	void Execute(const std::string& command) noexcept;
	void ChangePoseTo(const PoseHandler poseHandler) noexcept;

   private:
	PoseHandler poseHandler;
};

}  // namespace car
