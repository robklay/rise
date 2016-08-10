#pragma once

#include <algorithm>
#include <cassert>

namespace rok {

template <typename T>
T clamp(const T& n, const T& lower, const T& upper) {
	assert(lower <= upper);

	return std::max(lower, std::min(n, upper));
}

constexpr double PI = 3.141592653589793238463;
constexpr double DEG_TO_RAD_FACTOR = PI / 180.0;
constexpr double RAD_TO_DEG_FACTOR = 1.0 / DEG_TO_RAD_FACTOR;

} // namespace rok
