#pragma once

#include <SFML/Graphics.hpp>

#include "util/clock.hpp"

class Scene;

class Game {
public:
	Game();
	~Game();

	void run();

	static constexpr double STEPS_PER_SECOND = 30.0;
	static constexpr double TIME_STEP_MS = (1.0 / STEPS_PER_SECOND) * 1000.0;
	static constexpr double MAX_STEP_MS = 250;

	sf::RenderWindow window;

private:
	bool _running = false;

	Scene* _active_scene = nullptr;
	Scene* _next_scene = nullptr;

	rok::Clock _clock;
	double _accumulator = 0.0;
};
