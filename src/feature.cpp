#include "feature.hpp"

Feature::Feature(const rok::CoordinateList& coords) :
_coords(coords.coords_vector()),
_num_coords(coords.size()) {}

bool Feature::contains(const rok::Coordinate coord) const {
	for (const rok::Coordinate c : _coords.coords_vector()) {
		if (c == coord) {
			return true;
		}
	}

	return false;
}

const rok::Coordinate* Feature::coords() const {
	return _coords.coords_vector().data();
}

int Feature::num_coords() const {
	return _num_coords;
}
