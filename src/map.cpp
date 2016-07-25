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

void Map::set_heightmap(const rok::Matrix<rok::uint32>& matrix) {
	// Convert the 32-bit grayscale heightmap matrix into an 8-bit matrix.
	_heightmap.resize(matrix.size().x, matrix.size().y);
	for (int i = 0; i < matrix.size().x; ++i) {
		for (int j = 0; j < matrix.size().y; ++j) {
			_heightmap.set_element(i, j, (matrix.element(i, j) >> 8) & 0xFF);
		}
	}

	_terrain.resize(_heightmap.size().x, _heightmap.size().y);
	for (int i = 0; i < _size.x; ++i) {
		for (int j = 0; j < _size.y; ++j) {
			if (_heightmap.element(i, j) <= 94) {
				_terrain.set_element(i, j, Terrain::OCEAN);
			} else if (_heightmap.element(i, j) <= 134) {
				_terrain.set_element(i, j, Terrain::GRASSLAND);
			} else {
				_terrain.set_element(i, j, Terrain::HIGHLAND);
			}
		}
	}

	rok::Matrix<rok::uint32> terrain_colors;
	terrain_colors.resize(_terrain.size().x, _terrain.size().y);
	for (int i = 0; i < terrain_colors.size().x; ++i) {
		for (int j = 0; j < terrain_colors.size().y; ++j) {
			rok::Color color = rok::color_from_sf_color(terrain_color(_terrain.element(i, j)));
			terrain_colors.set_element(i, j, color.as_int());
		}
	}

	_terrain_texture.loadFromImage(rok::sf_image_from_matrix(terrain_colors));
	_terrain_sprite.setTexture(_terrain_texture);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_terrain_sprite, states);
	for (const FeaturePtr& f : _features) {
		target.draw(*f, states);
	}
}
