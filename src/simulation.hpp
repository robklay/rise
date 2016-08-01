#pragma once

#include "util/clock.hpp"

#include "world.hpp"

class Simulation : public rok::Drawable {
public:
	enum class Speed {
		PAUSED,
		SPEED_1 = 2000,
		SPEED_2 = 1000,
		SPEED_3 = 500,
		SPEED_MAX = 1, // Step as quickly as possible.
	};

	Simulation() = default;
	virtual ~Simulation() = default;

	void step();
	int step_number() const;

	void check_should_step();
	bool should_step() const;

	void set_speed(const Speed speed);
	Speed speed() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	rok::Clock _clock;
	bool _should_step = true;
	int _step_number = 0;
	Speed _speed = Speed::PAUSED;

	World _world;
};
