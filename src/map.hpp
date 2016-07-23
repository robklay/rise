#pragma once

#include "util/matrix.hpp"
#include "util/types.hpp"

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
