#include "pose.h"

#include <tuple>

namespace car {
bool operator==(const Pose& lhs, const Pose& rhs) {
	return std::tie(lhs.fastStatus, lhs.heading, lhs.x, lhs.y) ==
		   std::tie(rhs.fastStatus, rhs.heading, rhs.x, rhs.y);
}
}  // namespace car