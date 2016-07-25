#pragma once

#include "types.hpp"

namespace rok {

// A 32-bit color class.
class Color {
public:
	Color(const uint8 r = 0, const uint8 g = 0, const uint8 b = 0, const uint8 a = 0);
	Color(const uint32 color = 0);

	// Returns the color as a uint32.
	uint32 as_int() const;

	uint8 r;
	uint8 g;
	uint8 b;
	uint8 a;
};

} // namespace rok
