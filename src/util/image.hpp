#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "types.hpp"

namespace rok {

class Image {
public:
	Image(const int32 x = 0, const int32 y = 0);
	Image(const Image& image);
	Image& operator=(const Image& image);
	Image(const sf::Image& sf_image);

	void resize(const int32 x, const int32 y);
	int32 size_x() const;
	int32 size_y() const;
	const int32* pixels_ptr() const;

	void set_pixel_color(const int32 x, const int32 y, const int32 color);
	int32 pixel_color(const int32 x, const int32 y) const;

private:
	int32 _size_x;
	int32 _size_y;
	std::vector<int32> _pixels;
};

}
