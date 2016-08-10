#pragma once

#include <vector>

#include "types.hpp"

namespace rok {

struct Coordinate {
	Coordinate() = default;
	Coordinate(const int32 x, const int32 y);

	int32 x = 0;
	int32 y = 0;
};

inline bool operator==(const Coordinate left, const Coordinate right) {
	return left.x == right.x && left.y == right.y;
}

inline bool operator!=(const Coordinate left, const Coordinate right) {
	return !(left == right);
}

using CoordinateVector = std::vector<Coordinate>;

class CoordinateList {
public:
	CoordinateList() = default;
	CoordinateList(const CoordinateVector& coords);

	void add(const Coordinate coord);
	void remove(const Coordinate coord);

	bool contains(const Coordinate coord) const;

	int size() const;

	// Returns a coordinate containing the lowest x and y values in the list.
	Coordinate min() const;
	// Returns a coordinate containing the highest x and y values in the list.
	Coordinate max() const;

	// Returns a reference to the underlying vector used to store the coordinates.
	const CoordinateVector& coords_vector() const;

private:
	void update_bounds(const Coordinate coord);
	void reset_bounds();

	CoordinateVector _coords;
	int _size = 0;

	Coordinate _min;
	Coordinate _max;
};

} // namespace rok
