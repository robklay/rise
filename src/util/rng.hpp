#pragma once

#include <random>

#include "types.hpp"

namespace rok {

class Rng {
public:
	Rng() = default;
	Rng(const uint64 seed);

	void set_seed(const uint64 seed);
	uint64 seed() const;

private:
	std::mt19937 _generator;
	uint64 _seed;
};

} // namespace rok
