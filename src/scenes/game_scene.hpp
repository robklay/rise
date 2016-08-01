#pragma once

#include "../simulation.hpp"
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
	static constexpr double CAMERA_MIN_ZOOM = 0.1;
	static constexpr double CAMERA_MAX_ZOOM = 4.0;
	static constexpr double CAMERA_DEFAULT_ZOOM = 0.25;

	Simulation _simulation;

	double _camera_zoom = CAMERA_DEFAULT_ZOOM;
	sf::View _view;

	sf::Font _ui_font;
	sf::Text _step_text;

	bool _debug_mode = false;
	sf::Font _debug_font;
	sf::Text _debug_text;
};
