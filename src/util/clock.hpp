#pragma once

#include <chrono>

namespace rok {

class Clock {
public:
	enum class Unit {
		SECONDS = 1,
		MILLISECONDS = SECONDS * 1000,
		MICROSECONDS = MILLISECONDS * 1000,
		NANOSECONDS = MICROSECONDS * 1000,
	};

	Clock();

	// Starts the timer. Restarts it if start() was called previously.
	void start();
	// Returns the time since the most recent call to start() in the given unit.
	// Crashes if start() hasn't been called.
	double elapsed_time(const Unit unit) const;

private:
	std::chrono::steady_clock::time_point _start_time;
	bool _started;
};

} // namespace rok
