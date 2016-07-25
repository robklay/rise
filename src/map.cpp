#include "map.hpp"

#include "river.hpp"

Map::Map(const rok::Coordinate size) :
_size(size) {
	_features.emplace_back(new River(rok::CoordinateList({
		{ 3450, 400 },
		{ 3451, 400 },
		{ 3452, 400 },
		{ 3450, 401 },
		{ 3451, 401 },
		{ 3452, 401 },
		{ 3450, 402 },
		{ 3451, 402 },
		{ 3452, 402 },
		{ 3450, 403 },
		{ 3451, 403 },
		{ 3452, 403 },
	})));
}

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

	_terrain_texture.loadFromImage(sf_image_from_matrix(_terrain));
	_terrain_sprite.setTexture(_terrain_texture);
}

void Map::draw(sf::RenderWindow& window) const {
	window.draw(_terrain_sprite);
	for (const FeaturePtr& f : _features) {
		f->draw(window);
	}
}
