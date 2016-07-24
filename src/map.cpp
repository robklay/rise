#include "map.hpp"

Map::Map(const rok::Coordinate size) :
_size(size) {}

rok::Coordinate Map::size() const {
	return _size;
}

void Map::set_heightmap(const rok::Matrix<rok::uint32> matrix) {
	_heightmap = matrix;

	_terrain.resize(_heightmap.size().x, _heightmap.size().y);
	for (int i = 0; i < _size.x; ++i) {
		for (int j = 0; j < _size.y; ++j) {
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
