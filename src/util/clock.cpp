#include "clock.hpp"

#include <cassert>

namespace rok {

using Seconds = std::chrono::seconds;
using Milliseconds = std::chrono::milliseconds;
using Microseconds = std::chrono::microseconds;
using Nanoseconds = std::chrono::nanoseconds;
using SteadyClock = std::chrono::steady_clock;

void Clock::start() {
	_started = true;
	_start_time = SteadyClock::now();
}

bool Clock::started() const {
	return _started;
}

double Clock::elapsed_time(const Unit unit) const {
	assert(_started);

	const SteadyClock::time_point current_time = SteadyClock::now();
	const auto elapsed_time =
		std::chrono::duration_cast<Nanoseconds>(current_time - _start_time).count();

	switch (unit) {
	case Unit::SECONDS:
		return elapsed_time / static_cast<double>(Unit::NANOSECONDS);
	case Unit::MILLISECONDS:
		return elapsed_time / static_cast<double>(Unit::MICROSECONDS);
	case Unit::MICROSECONDS:
		return elapsed_time / static_cast<double>(Unit::MILLISECONDS);
	case Unit::NANOSECONDS:
		return static_cast<double>(elapsed_time);
	default:
		assert(false);
	}

	return 0.0;
}

uint64 Clock::now(const Unit unit) const {
	const SteadyClock::time_point current_time = SteadyClock::now();
	const auto time = current_time.time_since_epoch().count();

	switch (unit) {
	case Unit::SECONDS:
		return static_cast<uint64>(time / static_cast<double>(Unit::MILLISECONDS));
	case Unit::MILLISECONDS:
		return static_cast<uint64>(time);
	default:
		assert(false);
	}

	return 0;
}

} // namespace rok
