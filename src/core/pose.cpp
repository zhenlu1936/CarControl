#include "pose.h"

#include <tuple>

namespace car {

std::unordered_map<char, int> dir_char_to_int = {
	{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
std::unordered_map<int, char> dir_int_to_char = {
	{0, 'N'}, {1, 'E'}, {2, 'S'}, {3, 'W'}};
int forward[DIRECTIONS][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool Pose::operator==(const Pose& rhs) {
	return std::tie(fastStatus, direction, point) ==
		   std::tie(rhs.fastStatus, rhs.direction, rhs.point);
}

bool Point::operator==(const Point& rhs) {
	return (x == rhs.x) && (y == rhs.y);
}

bool Direction::operator==(const Direction& rhs) {
	return heading == rhs.heading;
}

Point& Point::operator+=(const Point& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Point& Point::operator-=(const Point& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Point Direction::Move(void) const noexcept {
	return Point(forward[dir_char_to_int[heading]][X],
				 forward[dir_char_to_int[heading]][Y]);
};

void Direction::TurnLeft(void) noexcept {
	heading = dir_int_to_char[(DIRECTIONS + dir_char_to_int[heading] - 1) %
							  DIRECTIONS];
}
void Direction::TurnRight(void) noexcept {
	heading = dir_int_to_char[(DIRECTIONS + dir_char_to_int[heading] + 1) %
							  DIRECTIONS];
}

}  // namespace car