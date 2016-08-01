#pragma once

#include "types.hpp"

namespace rok {

// A 32-bit color.
class Color {
public:
	Color() = default;
	Color(const uint8 r, const uint8 g, const uint8 b, const uint8 a);
	Color(const uint32 color);

	bool operator==(const Color right) const;
	bool operator!=(const Color right) const;

	// Returns the color as a uint32.
	uint32 as_int() const;

	uint8 r = 0;
	uint8 g = 0;
	uint8 b = 0;
	uint8 a = 0;
};

} // namespace rok
