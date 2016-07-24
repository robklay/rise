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

void Map::set_heightmap(const rok::Matrix<rok::uint32> matrix) {
	_heightmap = matrix;

	_terrain.resize(_heightmap.size_x(), _heightmap.size_y());
	for (int i = 0; i < _size_x; ++i) {
		for (int j = 0; j < _size_y; ++j) {
			if (_heightmap.element(i, j) >> 24 >= 94) {
				_terrain.set_element(i, j, 0x008000FF);
			} else {
				_terrain.set_element(i, j, 0x0000B4FF);
			}
		}
	}
}

const rok::Matrix<rok::uint32>& Map::heightmap() const {
	return _heightmap;
}

const rok::Matrix<rok::uint32>& Map::terrain() const {
	return _terrain;
}
