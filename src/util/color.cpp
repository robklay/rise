#include "color.hpp"

namespace rok {

Color::Color(const uint8 r, const uint8 g, const uint8 b, const uint8 a)
	: r(r)
	, g(g)
	, b(b)
	, a(a) {}

Color::Color(const uint32 color) {
	const uint8* pixel = reinterpret_cast<const uint8*>(&color);
	r = pixel[3];
	g = pixel[2];
	b = pixel[1];
	a = pixel[0];
}

bool Color::operator==(const Color right) const {
	return r == right.r && g == right.g && b == right.b && a == right.a;
}

bool Color::operator!=(const Color right) const {
	return !(*this == right);
}

uint32 Color::as_int() const {
	return r << 24 | g << 16 | b << 8 | a;
}

} // namespace rok
