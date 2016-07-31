#pragma once

#include "util/clock.hpp"
#include "util/sfml_helpers.hpp"

#include "calendar.hpp"
#include "map.hpp"

class Simulation : public rok::Drawable {
public:
	enum class Speed {
		PAUSED,
		SPEED_1 = 2000,
		SPEED_2 = 1000,
		SPEED_3 = 500,
		SPEED_MAX, // Step as quickly as possible.
	};

	Simulation();
	virtual ~Simulation() = default;

	void step();
	int step_number() const;

	void check_should_step();
	bool should_step() const;

	void set_speed(const Speed speed);
	Speed speed() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Calendar _calendar;
	rok::Clock _clock;
	bool _should_step;
	Speed _speed;

	Map _map;
};
