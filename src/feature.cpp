#include "feature.hpp"

Feature::Feature(const rok::Region& region)
	: _region(region.coords_vector())
	, _num_coords(region.size()) {}

bool Feature::contains(const rok::Coordinate coord) const {
	for (const rok::Coordinate c : _region.coords_vector()) {
		if (c == coord) return true;
	}

	return false;
}

const rok::Region Feature::region() const {
	return _region;
}

int Feature::num_coords() const {
	return _num_coords;
}
