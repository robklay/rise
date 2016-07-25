#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

#include "types.hpp"

namespace rok {

struct Coordinate {
	Coordinate(int32 x = 0, int32 y = 0) : x(x), y(y) {}

	int32 x = 0;
	int32 y = 0;
};

class CoordinateList {
public:
	CoordinateList();
	CoordinateList(const std::vector<Coordinate>& coords);

	void add(const Coordinate coord);
	void remove(const Coordinate coord);

	int size() const;

	// Returns a coordinate containing the lowest x and y values in the list.
	Coordinate min() const;
	// Returns a coordinate containing the highest x and y values in the list.
	Coordinate max() const;

	// Returns a reference to the underlying vector used to store the coordinates.
	const std::vector<Coordinate>& coords_vector() const;

private:
	void update_bounds(const Coordinate coord);
	void reset_bounds();

	std::vector<Coordinate> _coords;
	int _size;

	Coordinate _min;
	Coordinate _max;
};

inline bool operator==(Coordinate left, Coordinate right) {
	return left.x == right.x && left.y == right.y;
}

inline bool operator!=(Coordinate left, Coordinate right) {
	return left.x != right.x || left.y != right.y;
}

} // namespace rok
