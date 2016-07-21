#pragma once

#include "util/image.hpp"
#include "util/types.hpp"

class Map {
public:
	Map(const rok::int32 x = 0, const rok::int32 y = 0);

	rok::int32 size_x() const;
	rok::int32 size_y() const;

	void set_heightmap_image(const rok::Image image);

private:
	const rok::int32 _size_x;
	const rok::int32 _size_y;

	rok::Image _heightmap_image;
	rok::Image _terrain_image;
};
