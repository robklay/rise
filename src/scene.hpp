#pragma once

#include "game.hpp"

class Scene {
public:
	Scene(sf::RenderWindow& window);
	virtual ~Scene() = default;

	virtual void process_event(const sf::Event event) = 0;
	virtual void process_realtime_input() = 0;
	// Returns the scene to be switched to at the end of the game tick.
	// If no such switching is to occur, it should return "this".
	virtual Scene* update() = 0;
	virtual void draw() = 0;

protected:
	sf::RenderWindow& _window;
};
