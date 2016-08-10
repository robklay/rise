#include "coordinate.hpp"

#include <algorithm>

namespace rok {

Coordinate::Coordinate(const int32 x, const int32 y) :
x(x),
y(y) {}

CoordinateList::CoordinateList(const CoordinateVector& coords) :
_coords(coords),
_size(coords.size()) {
	if (_size > 0) {
		_min = { coords[0].x, coords[0].y };
		_max = { coords[0].x, coords[0].y };

		reset_bounds();
	}
}

void CoordinateList::add(const Coordinate coord) {
	if (_size == 0) {
		_min = { coord.x, coord.y };
		_max = { coord.x, coord.y };
	}
	update_bounds(coord);

	_coords.push_back(coord);
	++_size;
}

void CoordinateList::remove(const Coordinate coord) {
	if (_size == 0) return;

	const auto it = std::find(_coords.begin(), _coords.end(), coord);
	if (it == _coords.end()) return;

	_coords.erase(it);
	--_size;

	if (_size == 0) {
		_min = { 0, 0 };
		_max = { 0, 0 };
	}
	reset_bounds();
}

bool CoordinateList::contains(const Coordinate coord) const {
	return std::find(_coords.begin(), _coords.end(), coord) != _coords.end();
}

int CoordinateList::size() const {
	return _size;
}

Coordinate CoordinateList::min() const {
	return _min;
}

Coordinate CoordinateList::max() const {
	return _max;
}

const CoordinateVector& CoordinateList::coords_vector() const {
	return _coords;
}

void CoordinateList::update_bounds(const Coordinate coord) {
	if (coord.x < _min.x) _min.x = coord.x;
	if (coord.y < _min.y) _min.y = coord.y;
	if (coord.x > _max.x) _max.x = coord.x;
	if (coord.y > _max.y) _max.y = coord.y;
}

void CoordinateList::reset_bounds() {
	for (const Coordinate& c : _coords) {
		update_bounds(c);
	}
}

} // namespace rok
