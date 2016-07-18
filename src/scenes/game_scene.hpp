#pragma once

#include "../scene.hpp"
#include <SFML/Audio.hpp>

class GameScene : public Scene {
public:
	GameScene(sf::RenderWindow& window);

	virtual void process_event(const sf::Event event);
	virtual void process_realtime_input();
	virtual Scene* update();
	virtual void render();
};
