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
	rok::Matrix<rok::uint32> _terrain_temp;
	_terrain_temp.resize(_terrain.size().x, _terrain.size().y);

	// TODO: Clean this up.
	for (int i = 0; i < _size.x; ++i) {
		for (int j = 0; j < _size.y; ++j) {
			if (_heightmap.element(i, j) <= 94) {
				_terrain.set_element(i, j, Terrain::OCEAN);

				sf::Color sf_color = terrain_color(Terrain::OCEAN);
				sf::Uint8 arr[4];
				arr[0] = sf_color.r;
				arr[1] = sf_color.g;
				arr[2] = sf_color.b;
				arr[3] = sf_color.a;
				sf::Uint32 color = arr[0] << 24 | arr[1] << 16 | arr[2] << 8 | arr[3];

				_terrain_temp.set_element(i, j, static_cast<rok::uint32>(color));
			} else if (_heightmap.element(i, j) <= 128) {
				_terrain.set_element(i, j, Terrain::GRASSLAND);

				sf::Color sf_color = terrain_color(Terrain::GRASSLAND);
				sf::Uint8 arr[4];
				arr[0] = sf_color.r;
				arr[1] = sf_color.g;
				arr[2] = sf_color.b;
				arr[3] = sf_color.a;
				sf::Uint32 color = arr[0] << 24 | arr[1] << 16 | arr[2] << 8 | arr[3];

				_terrain_temp.set_element(i, j, static_cast<rok::uint32>(color));
			} else {
				_terrain.set_element(i, j, Terrain::HIGHLAND);

				sf::Color sf_color = terrain_color(Terrain::HIGHLAND);
				sf::Uint8 arr[4];
				arr[0] = sf_color.r;
				arr[1] = sf_color.g;
				arr[2] = sf_color.b;
				arr[3] = sf_color.a;
				sf::Uint32 color = arr[0] << 24 | arr[1] << 16 | arr[2] << 8 | arr[3];

				_terrain_temp.set_element(i, j, static_cast<rok::uint32>(color));
			}
		}
	}

	_terrain_texture.loadFromImage(sf_image_from_matrix(_terrain_temp));
	_terrain_sprite.setTexture(_terrain_texture);
}

void Map::draw(sf::RenderWindow& window) const {
	window.draw(_terrain_sprite);
	for (const FeaturePtr& f : _features) {
		f->draw(window);
	}
}
