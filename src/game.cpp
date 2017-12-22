#include "game.hpp"

#include <algorithm>
#include <cassert>

#include "scene.hpp"
#include "scenes/game_scene.hpp"

constexpr double Game::STEPS_PER_SECOND;
constexpr double Game::TIME_STEP_MS;
constexpr double Game::MAX_STEP_MS;

Game::Game() {
	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(1600, 900), "Rise", sf::Style::Close, context_settings);
	window.setVerticalSyncEnabled(true);

	_active_scene = new GameScene(window);
}

Game::~Game() {
	delete _active_scene;
}

void Game::run() {
	assert(!_running);

	_running = true;

	_clock.start();
	while (_running) {
		const double _step_ms =
			std::min(_clock.elapsed_time(rok::Clock::Unit::MILLISECONDS), MAX_STEP_MS);

		_clock.start();

		// Process SFML events.
		sf::Event event;
		while (window.pollEvent(event) != 0) {
			if (event.type == sf::Event::Closed) _running = false;
			else _active_scene->process_event(event);
		}

		// Process realtime input.
		_active_scene->process_realtime_input();

		// Update the game.
		_accumulator += _step_ms;
		while (_accumulator >= TIME_STEP_MS) {
			_next_scene = _active_scene->update();
			_accumulator -= TIME_STEP_MS;
		}

		// Draw the game.
		window.clear();
		_active_scene->draw();
		window.display();

		// Switches the active scene to the next scene if they are not the same.
		if (_next_scene != nullptr && _next_scene != _active_scene) {
			delete _active_scene;
			_active_scene = _next_scene;
			_next_scene = nullptr;
		}
	}

	window.close();
}
