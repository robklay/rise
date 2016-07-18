#include "clock.hpp"

#include <cassert>

namespace rok {

using Nanoseconds = std::chrono::nanoseconds;
using SteadyClock = std::chrono::steady_clock;

Clock::Clock() :
_started(false) {}

void Clock::start() {
	_started = true;
	_start_time = SteadyClock::now();
}

double Clock::elapsed_time(const Unit unit) {
	assert(_started);

	const SteadyClock::time_point current_time = SteadyClock::now();
	const Nanoseconds elapsed_time = current_time - _start_time;
	switch (unit) {
	case Unit::SECONDS:
		return std::chrono::duration_cast<Nanoseconds>(elapsed_time).count()
			/ static_cast<double>(Unit::NANOSECONDS);
	case Unit::MILLISECONDS:
		return std::chrono::duration_cast<Nanoseconds>(elapsed_time).count()
			/ static_cast<double>(Unit::MICROSECONDS);
	case Unit::MICROSECONDS:
		return std::chrono::duration_cast<Nanoseconds>(elapsed_time).count()
			/ static_cast<double>(Unit::MILLISECONDS);
	case Unit::NANOSECONDS:
		return static_cast<double>(std::chrono::duration_cast<Nanoseconds>(elapsed_time).count());
	default:
		assert(false);
	}

	return 0.0;
}

} // namespace rok
