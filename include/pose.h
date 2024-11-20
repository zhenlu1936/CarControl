#pragma once
#include <tuple>

namespace car {
struct Pose {
	bool fastStatus;
	int x, y;
	char heading;
	Pose(bool fastIn, int xIn, int yIn, char headingIn)
		: fastStatus(fastIn), x(xIn), y(yIn), heading(headingIn) {}
	Pose() : fastStatus(false), x(0), y(0), heading('N') {}
};

bool operator==(const Pose& lhs, const Pose& rhs);
}  // namespace car