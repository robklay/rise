#include "simulation.hpp"

void Simulation::step() {
	_should_step = false;

	if (_speed == Speed::PAUSED) return;
	++_step_number;

	_world.update();
}

int Simulation::step_number() const {
	return _step_number;
}

void Simulation::check_should_step() {
	if (!_clock.started()) {
		_clock.start();
		return;
	}

	if (_speed == Speed::SPEED_MAX) {
		_should_step = true;
		return;
	}

	const double elapsed_ms = _clock.elapsed_time(rok::Clock::Unit::MILLISECONDS);
	if (elapsed_ms >= static_cast<double>(_speed)) {
		_should_step = true;
		_clock.start();
	}
}

bool Simulation::should_step() const {
	return _should_step;
}

void Simulation::set_speed(const Speed speed) {
	_speed = speed;
}

Simulation::Speed Simulation::speed() const {
	return _speed;
}

void Simulation::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_world, states);
}
