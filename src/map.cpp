#include "map.hpp"

Map::Map(const rok::int32 x, const rok::int32 y) :
_size_x(x),
_size_y(y) {}

rok::int32 Map::size_x() const {
	return _size_x;
}

rok::int32 Map::size_y() const {
	return _size_y;
}

void Map::set_heightmap(const rok::Matrix<rok::int32> matrix) {
	_heightmap = matrix;
}
