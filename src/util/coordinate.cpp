#include "coordinate.hpp"

namespace rok {

CoordinateList::CoordinateList() :
_size(0) {}

CoordinateList::CoordinateList(const std::vector<Coordinate>& coords) :
_coords(coords),
_size(coords.size()) {
	if (_size > 0) {
		_min = { coords[0].x, coords[0].y };
		_max = { coords[0].x, coords[0].y };
	}

	reset_bounds();
}

void CoordinateList::add(const Coordinate coord) {
	if (_size == 0) {
		_min = { coord.x, coord.y };
		_max = { coord.x, coord.y };
	} else {
		update_bounds(coord);
	}

	_coords.push_back(coord);
}

void CoordinateList::remove(const Coordinate coord) {
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

int CoordinateList::size() const {
	return _size;
}

Coordinate CoordinateList::min() const {
	return _min;
}

Coordinate CoordinateList::max() const {
	return _max;
}

const std::vector<Coordinate>& CoordinateList::coords_vector() const {
	return _coords;
}

void CoordinateList::update_bounds(const Coordinate coord) {
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

void CoordinateList::reset_bounds() {
	for (const Coordinate& c : _coords) {
		update_bounds(c);
	}
}

} // namespace rok
