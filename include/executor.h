#pragma once
#include <map>
#include <string>

#define DIRECTIONS 4
#define X 0
#define Y 1

namespace car {

struct Pose {
	int x, y;
	char heading;
};

extern std::map<char, int> dir;
extern int forward[DIRECTIONS][2];

class Executor {
   protected:
	Pose pose;

   public:
	static Executor* NewExecutor(const Pose& pose = {0, 0, 'N'});

	Executor() = default;
	virtual ~Executor() = default;

	Executor(const Executor&) = delete;
	Executor& operator=(const Executor&) = delete;

   public:
	virtual void Execute(const std::string& command) noexcept = 0;
	virtual Pose Query() const noexcept = 0;
};

class ExecutorImpl : public Executor {
   public:
	static ExecutorImpl* NewExecutor(const Pose& pose = {0, 0, 'N'});

	ExecutorImpl(const Pose& poseIn);

   public:
	virtual void Execute(const std::string& command) noexcept;
	virtual Pose Query() const noexcept;
};

}  // namespace car
