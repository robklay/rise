#pragma once

#include "../world.hpp"
#include "../scene.hpp"

class GameScene : public Scene {
public:
	GameScene(sf::RenderWindow& window);

	virtual void process_event(const sf::Event event) override;
	virtual void process_realtime_input() override;
	virtual Scene* update() override;
	virtual void draw() override;

private:
	// TODO: Make camera moving and zooming better.
	static constexpr double CAMERA_SPEED = 5.0;
	static constexpr double CAMERA_ZOOM_SPEED = 0.25;
	static constexpr double CAMERA_MIN_ZOOM = 0.25;
	static constexpr double CAMERA_MAX_ZOOM = 4.0;

	World _world;

	sf::View _view;
	double _camera_zoom;
};
