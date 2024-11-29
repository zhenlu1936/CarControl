#pragma once
#include <map>
#include <tuple>

#define DIRECTIONS 4
#define X 0
#define Y 1

namespace car {

extern std::unordered_map<char, int> dir_char_to_int;
extern std::unordered_map<int, char> dir_int_to_char;
extern int forward[DIRECTIONS][2];

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