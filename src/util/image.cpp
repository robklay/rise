#include "image.hpp"

#include <algorithm>
#include <cassert>

namespace rok {

Image::Image(const int32 x, const int32 y) :
_size_x(x),
_size_y(y),
_pixels(x * y) {
	assert(x >= 0 && y >= 0);
}

Image::Image(const Image& image) :
_size_x(image.size_x()),
_size_y(image.size_y()) {
	if (this != &image) {
		_pixels.resize(image.size_x() * image.size_y());
		std::copy_n(image.pixels_ptr(), _size_x * _size_y, _pixels.begin());
	}
}

Image& Image::operator=(const Image& image) {
	if (this != &image) {
		resize(image.size_x(), image.size_y());
		std::copy_n(image.pixels_ptr(), _size_x * _size_y, _pixels.begin());
	}

	return *this;
}

Image::Image(const sf::Image& sf_image) :
Image(sf_image.getSize().x, sf_image.getSize().y) {
	for (int i = 0; i < _size_x; ++i) {
		for (int j = 0; j < _size_y; ++j) {
			set_pixel_color(i, j, static_cast<int32>(sf_image.getPixel(i, j).toInteger()));
		}
	}
}

void Image::resize(const int32 x, const int32 y) {
	_size_x = x;
	_size_y = y;
	_pixels.resize(x * y);
}

int32 Image::size_x() const {
	return _size_x;
}

int32 Image::size_y() const {
	return _size_y;
}

const int32* Image::pixels_ptr() const {
	return _pixels.data();
}

void Image::set_pixel_color(const int32 x, const int32 y, const int32 color) {
	assert(x >= 0 && x <= _size_x && y >= 0 && y <= _size_y);

	_pixels[x + y * _size_x] = color;
}

int32 Image::pixel_color(const int32 x, const int32 y) const {
	assert(x >= 0 && x <= _size_x && y >= 0 && y <= _size_y);

	return _pixels[x + y * _size_x];
}

}
