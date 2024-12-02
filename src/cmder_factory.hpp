#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "command.hpp"

namespace car {
class CmderFactory final {
   public:
	CmderFactory(void) noexcept = default;
	~CmderFactory(void) noexcept = default;
	CmderFactory(const CmderFactory&) noexcept = delete;
	CmderFactory& operator=(const CmderFactory&) noexcept = delete;

	std::list<std::function<void(PoseHandler& PoseHandler)>> GetCmders(
		const std::string& commands) {
		std::list<std::function<void(PoseHandler & poseHandler)>> cmders;
		for (const auto command : commands) {
			const auto it = cmderMap.find(command);
			if (it != cmderMap.end()) {
				cmders.push_back(it->second);
			}
		}
		return cmders;
	}

   private:
	const std::unordered_map<char,
							 std::function<void(PoseHandler& poseHandler)>>
		cmderMap{{'M', MoveCommand()},
				 {'L', TurnLeftCommand()},
				 {'R', TurnRightCommand()},
				 {'F', FastCommand()},
				 {'B', BackCommand()}};
};
}  // namespace car