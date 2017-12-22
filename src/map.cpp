#include "map.hpp"

#include <cassert>

//#include "settlement.hpp"
//#include "river.hpp"

Map::Map(const rok::Coordinate size)
		: _size(size)
		, _map_mode(MapMode::TERRAIN) {
	_heightmap.resize(_size);
	_terrain.resize(_size);
	_owner.resize(_size);
}

rok::Coordinate Map::size() const {
	return _size;
}

void Map::set_heightmap(const rok::Matrix<rok::uint32>& matrix) {
	assert(matrix.size() == _size);

	rok::Matrix<rok::uint32> terrain_colors;
	terrain_colors.resize(_size);

	for (int i = 0; i < matrix.size().x; ++i) {
		for (int j = 0; j < matrix.size().y; ++j) {
			_heightmap.element(i, j) = (matrix.element(i, j) >> 8) & 0xFF;

			rok::Color color;
			if (_heightmap.element(i, j) <= 94) {
				_terrain.element(i, j) = Terrain::OCEAN;
				color = rok::Color(0, 51, 204);
			} else if (_heightmap.element(i, j) <= 124) {
				_terrain.element(i, j) = Terrain::GRASSLAND;
				color = rok::Color(0, 153, 0);
			} else {
				_terrain.element(i, j) = Terrain::HIGHLAND;
				color = rok::Color(102, 51, 0);
			}


			terrain_colors.element(i, j) = color.as_int();
		}
	}

	_terrain_texture.loadFromImage(rok::sf_image_from_matrix(terrain_colors));
	_terrain_sprite.setTexture(_terrain_texture);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	switch (_map_mode) {
	case MapMode::TERRAIN:
		target.draw(_terrain_sprite, states);
		break;
	case MapMode::POLITICAL:
		target.draw(_political_sprite, states);
	}

	/*for (const FeatureUPtr& f : _features) {
		target.draw(*f, states);
	}*/
}
