#pragma once

#include <algorithm>
#include <cassert>

#include "types.hpp"

namespace rok {

struct Coordinate {
	Coordinate(int32 x = 0, int32 y = 0) : x(x), y(y) {}

	int32 x = 0;
	int32 y = 0;
};

class CoordinateList {
public:
	CoordinateList() : _size(0), _min({ 0, 0 }), _max({ 0, 0 }) {}
	CoordinateList(const std::vector<Coordinate>& coords) : _coords(coords), _size(coords.size()) {
		if (_size > 0) {
			_min = { coords[0].x, coords[0].y };
			_max = { coords[0].x, coords[0].y };
		}

		reset_bounds();
	}

	void add(const Coordinate coord) {
		if (_size == 0) {
			_min = { coord.x, coord.y };
			_max = { coord.x, coord.y };
		} else {
			update_bounds(coord);
		}

		_coords.push_back(coord);
	}

	void remove(const Coordinate coord) {
		if (_size == 0) return;

		auto it = std::find(_coords.begin(), _coords.end(), coord);
		if (it == _coords.end()) return;

		_coords.erase(it);
		--_size;
		if (_size == 0) {
			_min = { 0, 0 };
			_max = { 0, 0 };
		} else {
			reset_bounds();
		}
	}

	int size() const { return _size; }

	// Returns a coordinate containing the lowest x and y values in the list.
	Coordinate min() const { return _min; }
	// Returns a coordinate containing the highest x and y values in the list.
	Coordinate max() const { return _max; }

	// Returns a reference to the underlying vector used to store the coordinates.
	const std::vector<Coordinate>& coords_vector() const { return _coords; }

private:
	void update_bounds(const Coordinate coord) {
		if (coord.x < _min.x) {
			_min.x = coord.x;
		}
		if (coord.y < _min.y) {
			_min.y = coord.y;
		}
		if (coord.x > _max.x) {
			_max.x = coord.x;
		}
		if (coord.y > _max.y) {
			_max.y = coord.y;
		}
	}

	void reset_bounds() {
		for (const Coordinate& c : _coords) {
			update_bounds(c);
		}
	}

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
