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

class Point {
   public:
	int x, y;

	Point(int xIn, int yIn) : x(xIn), y(yIn) {}
	Point& operator+=(const Point& rhs);
	Point& operator-=(const Point& rhs);
	bool operator==(const Point& rhs);
};

class Direction {
   public:
	char heading;

	Direction(char headingIn) : heading(headingIn) {}
	Point Move(void) const noexcept;
	void TurnLeft(void) noexcept;
	void TurnRight(void) noexcept;
	bool operator==(const Direction& rhs);
};

class Pose {
   public:
	bool fastStatus;
	bool backStatus;
	Point point;
	Direction direction;
	Pose(int xIn, int yIn, char headingIn)
		: fastStatus(false),
		  backStatus(false),
		  point(xIn, yIn),
		  direction(headingIn) {}
	Pose(bool fastIn, int xIn, int yIn, char headingIn)
		: fastStatus(fastIn),
		  backStatus(false),
		  point(xIn, yIn),
		  direction(headingIn) {}
	Pose(bool fastIn, bool backIn, int xIn, int yIn, char headingIn)
		: fastStatus(fastIn),
		  backStatus(backIn),
		  point(xIn, yIn),
		  direction(headingIn) {}
	Pose()
		: fastStatus(false), backStatus(false), point(0, 0), direction('N') {}
	bool operator==(const Pose& rhs);
};

}  // namespace car