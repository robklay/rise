#pragma once

#include <algorithm>
#include <cassert>

namespace rok {

template <typename T>
T clamp(const T& n, const T& lower, const T& upper) {
	assert(lower < upper);
	return std::max(lower, std::min(n, upper));
}

} // namespace rok
