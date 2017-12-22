#include "rng.hpp"

namespace rok {

Rng::Rng(const uint64 seed)
	: _seed(seed) {}

void Rng::set_seed(const uint64 seed) {
	_seed = seed;
}

uint64 Rng::seed() const {
	return _seed;
}

} // namespace rok
