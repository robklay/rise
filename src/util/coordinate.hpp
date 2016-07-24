#pragma once

#include "types.hpp"

namespace rok {

struct Coordinate {
	Coordinate(int32 x, int32 y) : x(x), y(y) {}

	int32 x = 0;
	int32 y = 0;
};

inline bool operator==(Coordinate left, Coordinate right) {
	return left.x == right.x && left.y == right.y;
}

inline bool operator!=(Coordinate left, Coordinate right) {
	return left.x != right.x || left.y != right.y;
}

} // namespace rok
