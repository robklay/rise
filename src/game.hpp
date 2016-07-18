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
	static constexpr double TIME_STEP = 1.0 / STEPS_PER_SECOND;
	static constexpr double MAX_STEP_SECONDS = 0.25;

	sf::RenderWindow window;

private:
	void process_events();
	void process_realtime_input();
	void update();
	void render();

	static bool _instantiated;

	bool _running;
	Scene* _active_scene;
	Scene* _next_scene;

	rok::Clock _step_clock;
	double _tick_time;
	double _accumulator;
};
