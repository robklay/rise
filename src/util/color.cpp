#include "color.hpp"

namespace rok {

Color::Color(const uint8 r, const uint8 g, const uint8 b, const uint8 a) :
r(r),
g(g),
b(b),
a(a) {}

Color::Color(const uint32 color) {
	uint8* pixel = (uint8*) &color;
	r = pixel[3];
	g = pixel[2];
	b = pixel[1];
	a = pixel[0];
}

uint32 Color::as_int() const {
	return r << 24 | g << 16 | b << 8 | a;
}

} // namespace rok
