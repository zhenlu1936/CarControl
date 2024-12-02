#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "command.hpp"

namespace car {
using Cmder = std::function<void(PoseHandler& poseHandler)>;

class CmderFactory final {
   public:
	CmderFactory(void) noexcept = default;
	~CmderFactory(void) noexcept = default;
	CmderFactory(const CmderFactory&) noexcept = delete;
	CmderFactory& operator=(const CmderFactory&) noexcept = delete;

	std::list<Cmder> GetCmders(const std::string& commands) {
		std::list<Cmder> cmders;
		for (const auto command : commands) {
			const auto it = cmderMap.find(command);
			if (it != cmderMap.end()) {
				cmders.push_back(it->second);
			}
		}
		return cmders;
	}

   private:
	const std::unordered_map<char, Cmder> cmderMap{{'M', MoveCommand()},
												   {'L', TurnLeftCommand()},
												   {'R', TurnRightCommand()},
												   {'F', FastCommand()},
												   {'B', BackCommand()}};
};
}  // namespace car