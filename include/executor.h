#pragma once
#include <map>
#include <string>

#define DIRECTIONS 4
#define X 0
#define Y 1

namespace car {

struct Pose {
	bool fastStatus;
	int x, y;
	char heading;
};

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
	virtual void Execute(const std::string& command) noexcept = 0;
	virtual Pose Query() const noexcept = 0;
};

class ExecutorImpl : public Executor {
   public:
	static ExecutorImpl* NewExecutor(const Pose& pose = {false, 0, 0, 'N'});
	ExecutorImpl(const Pose& poseIn);

	virtual Pose Query() const noexcept;
	virtual void Execute(const std::string& command) noexcept;

   private:
	void ChangePoseTo(const Pose& pose) noexcept;

	static void Move(Pose& currentPose) noexcept;
	static void TurnLeft(Pose& currentPose) noexcept;
	static void TurnRight(Pose& currentPose) noexcept;
	static void EnableFast(Pose& currentPose) noexcept;
	static void DisableFast(Pose& currentPose) noexcept;

	class ICommand {
	   public:
		virtual ~ICommand() = default;
		virtual void Operate(ExecutorImpl& executor) const noexcept = 0;
	};

	class MoveCommand : public ICommand {
	   public:
		void Operate(ExecutorImpl& executor) const noexcept {
			Pose currentPose = executor.Query();
			Move(currentPose);
			executor.ChangePoseTo(currentPose);
		}
	};

	class TurnLeftCommand : public ICommand {
	   public:
		void Operate(ExecutorImpl& executor) const noexcept {
			Pose currentPose = executor.Query();
			TurnLeft(currentPose);
			executor.ChangePoseTo(currentPose);
		}
	};

	class TurnRightCommand : public ICommand {
	   public:
		void Operate(ExecutorImpl& executor) const noexcept {
			Pose currentPose = executor.Query();
			TurnRight(currentPose);
			executor.ChangePoseTo(currentPose);
		}
	};

	class FastCommand : public ICommand {
	   public:
		void Operate(ExecutorImpl& executor) const noexcept {
			Pose currentPose = executor.Query();
			if (currentPose.fastStatus == false) {
				EnableFast(currentPose);
			} else
				DisableFast(currentPose);
			executor.ChangePoseTo(currentPose);
		}
	};
};

}  // namespace car
