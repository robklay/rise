#pragma once

#include <memory>
#include <type_traits>
#include <vector>

#include <SFML/Graphics.hpp>

#include "util/matrix.hpp"
#include "util/types.hpp"

#include "feature.hpp"

// Creates and returns a Matrix of the desired type based on an sf::Image.
// Only supports types int32 and uint32.
template <typename T>
rok::Matrix<T> matrix_from_sf_image(const sf::Image& sf_image) {
	static_assert(std::is_same<T, rok::int32>::value || std::is_same<T, rok::uint32>::value,
	              "matrix_from_sf_image() only supports types int32 and uint32");

	rok::Matrix<T> matrix;
	sf::Vector2u size = sf_image.getSize();

	matrix.resize(size.x, size.y);
	for (size_t i = 0; i < size.x; ++i) {
		for (size_t j = 0; j < size.y; ++j) {
			matrix.set_element(i, j, static_cast<T>(sf_image.getPixel(i, j).toInteger()));
		}
	}

	return matrix;
}

// Creates and returns an sf::Image from a Matrix.
// Only supports Matrices of types int32 and uint32.
template <typename T>
sf::Image sf_image_from_matrix(const rok::Matrix<T>& matrix) {
	static_assert(std::is_same<T, rok::int32>::value || std::is_same<T, rok::uint32>::value,
	              "sf_image_from_matrix() only supports Matrices of types int32 and uint32");

	sf::Image sf_image;
	sf_image.create(matrix.size().x, matrix.size().y);

	for (int i = 0; i < matrix.size().x; ++i) {
		for (int j = 0; j < matrix.size().y; ++j) {
			sf::Uint8* pixel = (sf::Uint8*) &(matrix.data()[i + j * matrix.size().x]);
			sf_image.setPixel(i, j, sf::Color(pixel[3], pixel[2], pixel[1], pixel[0]));
		}
	}

	return sf_image;
}

enum class Terrain : rok::uint8 {
	OCEAN,
	GRASSLAND,
	HIGHLAND,
};

inline sf::Color terrain_color(const Terrain terrain) {
	switch (terrain) {
	case Terrain::OCEAN:
		return sf::Color(0, 51, 204);
	case Terrain::GRASSLAND:
		return sf::Color(0, 153, 0);
	case Terrain::HIGHLAND:
		return sf::Color(102, 51, 0);
	default:
		assert(false);
	}

	return sf::Color::Black;
}

class Map {
public:
	Map(const rok::Coordinate size = { 0, 0 });

	rok::Coordinate size() const;

	void set_heightmap(const rok::Matrix<rok::uint32>& matrix);

	void draw(sf::RenderWindow& window) const;

private:
	using FeaturePtr = std::unique_ptr<Feature>;

	const rok::Coordinate _size;

	rok::Matrix<rok::uint8> _heightmap;
	rok::Matrix<Terrain> _terrain;
	std::vector<FeaturePtr> _features;

	sf::Texture _terrain_texture;
	sf::Sprite _terrain_sprite;
};
