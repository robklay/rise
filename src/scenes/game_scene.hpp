#pragma once

#include "../map.hpp"
#include "../scene.hpp"

class GameScene : public Scene {
public:
	GameScene(sf::RenderWindow& window);

	virtual void process_event(const sf::Event event);
	virtual void process_realtime_input();
	virtual Scene* update();
	virtual void render();

private:
	static constexpr double CAMERA_SPEED = 5.0;
	static constexpr double CAMERA_ZOOM_SPEED = 0.25;
	static constexpr double CAMERA_MIN_ZOOM = 0.25;
	static constexpr double CAMERA_MAX_ZOOM = 4.0;

	Map _map;

	sf::View _view;
	double _camera_zoom;

	sf::Texture _terrain_texture;
	sf::Sprite _terrain_sprite;
};
