#pragma once

#include <cstdint>
#include <type_traits>

#include <SFML/Graphics.hpp>

#include "color.hpp"
#include "matrix.hpp"

namespace rok {

// Tools that help deal with a using a mixure of SFML and Rok utilities in the code.
// This file keeps the game's code relatively independent of SFML so that if needed,
// SFML can be removed.

// Creates and returns a rok::Matrix of the desired type based on an sf::Image.
// Only supports types int32 and uint32.
template <typename T>
Matrix<T> matrix_from_sf_image(const sf::Image& sf_image) {
	const bool is_32_bit = std::is_same<T, int32>::value || std::is_same<T, uint32>::value;
	static_assert(is_32_bit, "matrix_from_sf_image() only supports types int32 and uint32");

	Matrix<T> matrix;
	sf::Vector2u size = sf_image.getSize();

	matrix.resize(size.x, size.y);
	for (size_t i = 0; i < size.x; ++i) {
		for (size_t j = 0; j < size.y; ++j) {
			matrix.set_element(i, j, static_cast<T>(sf_image.getPixel(i, j).toInteger()));
		}
	}

	return matrix;
}

// Creates and returns an sf::Image from a rok::Matrix.
// Only supports Matrices of types int32, uint32, int8, and uint8.
// Given an 8-bit matrix (int8 or uint8), treats it as a grayscale image and
// converts it into a 32-bit grayscale sf::Image with an alpha of 255.
template <typename T>
sf::Image sf_image_from_matrix(const Matrix<T>& matrix) {
	const bool is_32_bit = std::is_same<T, int32>::value || std::is_same<T, uint32>::value;
	const bool is_8_bit = std::is_same<T, int8>::value || std::is_same<T, uint8>::value;

	static_assert(is_32_bit || is_8_bit,
	              "sf_image_from_matrix() only supports Matrices "
	              "of types int32, uint32, int8, and uint8");

	sf::Image sf_image;
	sf_image.create(matrix.size().x, matrix.size().y);

	for (int i = 0; i < matrix.size().x; ++i) {
		for (int j = 0; j < matrix.size().y; ++j) {
			sf::Uint8* color = (sf::Uint8*) &(matrix.data()[i + j * matrix.size().x]);

			if (is_32_bit) {
				sf_image.setPixel(i, j, sf::Color(color[3], color[2], color[1], color[0]));
			} else if (is_8_bit) {
				sf_image.setPixel(i, j, sf::Color(color[0], color[0], color[0], 0xFF));
			} else {
				// If somehow T isn't one of the accepted types.
				assert(false);
			}
		}
	}

	return sf_image;
}

// Creates and returns a rok::Color from an sf::Color.
Color color_from_sf_color(const sf::Color sf_color);

//Creates and returns an sf::Color from a rok::Color.
sf::Color sf_color_from_color(const Color color);

class Drawable : public sf::Drawable {
public:
	virtual ~Drawable() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};

} // namespace rok
