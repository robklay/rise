#pragma once

#include <type_traits>

#include "util/matrix.hpp"
#include "util/types.hpp"

// Creates and returns a matrix of the desired type based on an sf::Image.
template <typename T>
rok::Matrix<T> matrix_from_sf_image(const sf::Image& sf_image) {
	// This function probably shouldn't support non-integral types.
	static_assert(std::is_integral<T>);

	rok::Matrix<T> matrix;
	sf::Vector2u size = sf_image.getSize();

	matrix.resize(size.x, size.y);
	for (int i = 0; i < size.x; ++i) {
		for (int j = 0; j < size.y; ++j) {
			matrix.set_element(i, j, static_cast<T>(sf_image.getPixel(i, j).toInteger()));
		}
	}
}

class Map {
public:
	Map(const rok::int32 x = 0, const rok::int32 y = 0);

	rok::int32 size_x() const;
	rok::int32 size_y() const;

	void set_heightmap(const rok::Matrix<rok::int32> matrix);

private:
	const rok::int32 _size_x;
	const rok::int32 _size_y;

	rok::Matrix<rok::int32> _heightmap;
	rok::Matrix<rok::int32> _terrain;
};
