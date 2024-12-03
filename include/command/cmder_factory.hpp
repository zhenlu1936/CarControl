#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "action_group.h"
#include "command.hpp"

namespace car {
using Cmder = std::function<ActionGroup(PoseHandler& poseHandler)>;

class CmderFactory final {
   public:
	CmderFactory(void) noexcept = default;
	~CmderFactory(void) noexcept = default;
	CmderFactory(const CmderFactory&) noexcept = delete;
	CmderFactory& operator=(const CmderFactory&) noexcept = delete;

	std::list<Cmder> GetCmders(const std::string& commands) {
		auto cmderMap = cmderMapNormal;
		std::list<Cmder> cmders;
		for (const auto command : commands) {
			const auto it = cmderMap.find(command);
			if (it != cmderMap.end()) {
				cmders.push_back(it->second);
			}
		}
		return cmders;
	}

	void ReplaceAll(std::string& inout, std::string_view what,
					std::string_view with) const noexcept {
		for (std::string::size_type pos{};
			 inout.npos != (pos = inout.find(what.data(), pos, what.length()));
			 pos += with.length()) {
			inout.replace(pos, what.length(), with.data(), with.length());
		}
	}

	std::string ParseCommandString(std::string_view commands) const noexcept {
		std::string result(commands);
		ReplaceAll(result, "TR", "Z");
		return result;
	}

   private:
	const std::unordered_map<char, Cmder> cmderMapNormal{
		{'M', MoveCommand()},	   {'L', TurnLeftCommand()},
		{'R', TurnRightCommand()}, {'Z', TurnRoundCommand()},
		{'F', FastCommand()},	   {'B', BackCommand()}};

	const std::unordered_map<char, Cmder> cmderMapSports{
		{'M', MoveCommandSports()},
		{'L', TurnLeftCommandSports()},
		{'R', TurnRightCommandSports()},
		{'Z', TurnRoundCommand()},
		{'F', FastCommand()},
		{'B', BackCommand()}};

	const std::unordered_map<char, Cmder> cmderMapBus{
		{'M', MoveCommandBus()},	  {'L', TurnLeftCommandBus()},
		{'R', TurnRightCommandBus()}, {'Z', TurnRoundCommand()},
		{'F', FastCommand()},		  {'B', BackCommand()}};
};
}  // namespace car