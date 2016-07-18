#include "game.hpp"

#include <algorithm>
#include <cassert>

#include "scene.hpp"
#include "scenes/game_scene.hpp"

bool Game::_instantiated = false;

Game::Game() :
_running(false),
_active_scene(new GameScene(window)),
_next_scene(nullptr),
_tick_time(0.0),
_accumulator(0.0) {
	assert(!_instantiated);
	_instantiated = true;

	sf::ContextSettings context_settings;
	context_settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(1600, 900), "Rise", sf::Style::Close, context_settings);
	window.setVerticalSyncEnabled(true);
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
		_tick_time = std::min(elapsed_ms / 1000, MAX_STEP_SECONDS);

		_step_clock.start();

		process_events();
		process_realtime_input();
		update();
		render();

		if (_next_scene) {
			delete _active_scene;
			_active_scene = _next_scene;
			_next_scene = nullptr;
		}
	}

	window.close();
}

void Game::process_events() {
	sf::Event event;
	while (window.pollEvent(event) != 0) {
		if (event.type == sf::Event::Closed) {
			_running = false;
		}
		else {
			_active_scene->process_event(event);
		}
	}
}

void Game::process_realtime_input() {
	_active_scene->process_realtime_input();
}

void Game::update() {
	_accumulator += _tick_time;
	while (_accumulator >= TIME_STEP) {
		_accumulator -= TIME_STEP;

		_next_scene = _active_scene->update();
		if (_next_scene == _active_scene) {
			_next_scene = nullptr;
		}

	}
}

void Game::render() {
	window.clear();
	_active_scene->render();
	window.display();
}
