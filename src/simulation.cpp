#include "simulation.hpp"

Simulation::Simulation() :
_should_step(true),
_speed(Speed::PAUSED),
_map({ 5632, 2048 }) {
	sf::Image heightmap_image;
	heightmap_image.loadFromFile("data/heightmap.png");
	_map.set_heightmap(rok::matrix_from_sf_image<rok::uint32>(heightmap_image));
}

void Simulation::step() {
	_should_step = false;

	if (_speed == Speed::PAUSED) return;
	_calendar.step();
}

int Simulation::step_number() const {
	return _calendar.step_number();
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
	target.draw(_map, states);
}
