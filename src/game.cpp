#include "game.hpp"

#include <algorithm>
#include <cassert>

#include "scene.hpp"
#include "scenes/game_scene.hpp"

constexpr double Game::STEPS_PER_SECOND;
constexpr double Game::TIME_STEP;
constexpr double Game::MAX_STEP_SECONDS;

bool Game::_instantiated = false;

Game::Game() :
_running(false),
_next_scene(nullptr),
_tick_time(0.0),
_accumulator(0.0) {
	assert(!_instantiated);
	_instantiated = true;

	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(1600, 900), "Rise", sf::Style::Close, context_settings);
	window.setVerticalSyncEnabled(true);

	_active_scene = new GameScene(window);
}

Game::~Game() {
	delete _active_scene;
	_active_scene = nullptr;
	delete _next_scene;
	_next_scene = nullptr;
}

void Game::run() {
	assert(!_running);
	_running = true;

	_step_clock.start();
	while (_running) {
		double elapsed_ms = _step_clock.elapsed_time(rok::Clock::Unit::MILLISECONDS);
		_tick_time = std::min(elapsed_ms / static_cast<double>(rok::Clock::Unit::MILLISECONDS),
		                      MAX_STEP_SECONDS);

		_step_clock.start();

		// Process SFML events.
		sf::Event event;
		while (window.pollEvent(event) != 0) {
			if (event.type == sf::Event::Closed) {
				_running = false;
			}
			else {
				_active_scene->process_event(event);
			}
		}

		// Process realtime input.
		_active_scene->process_realtime_input();

		// Update the game.
		_accumulator += _tick_time;
		while (_accumulator >= TIME_STEP) {
			_accumulator -= TIME_STEP;

			_next_scene = _active_scene->update();
			if (_next_scene == _active_scene) {
				_next_scene = nullptr;
			}
		}

		// Render the game.
		window.clear();
		_active_scene->render();
		window.display();

		if (_next_scene) {
			delete _active_scene;
			_active_scene = _next_scene;
			_next_scene = nullptr;
		}
	}

	window.close();
}
