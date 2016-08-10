#include "game_scene.hpp"

#include <string>

#include "../util/math.hpp"
#include "../util/sfml_helpers.hpp"

constexpr double GameScene::CAMERA_SPEED;
constexpr double GameScene::CAMERA_ZOOM_SPEED;
constexpr double GameScene::CAMERA_MIN_ZOOM;
constexpr double GameScene::CAMERA_MAX_ZOOM;

GameScene::GameScene(sf::RenderWindow& window) :
Scene(window),
_view(sf::FloatRect(0.0f, 0.0f,
                    static_cast<float>(window.getSize().x * _camera_zoom),
                    static_cast<float>(window.getSize().y * _camera_zoom))) {
	_ui_font.loadFromFile("data/fonts/roboto.ttf");
	_step_text.setFont(_ui_font);
	_step_text.setCharacterSize(24);
	_step_text.setColor(sf::Color::Black);

	_debug_font.loadFromFile("data/fonts/source_code_pro.ttf");
	_debug_text.setFont(_debug_font);
	_debug_text.setCharacterSize(24);
	_debug_text.setPosition(25.0f, 25.0f);
	_debug_text.setColor(sf::Color::Black);
}

void GameScene::process_event(const sf::Event event) {
	// Camera zooming.
	if (event.type == sf::Event::MouseWheelScrolled) {
		if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
			double zoom_factor =
				1.0 + static_cast<double>(event.mouseWheelScroll.delta) * -CAMERA_ZOOM_SPEED;

			_camera_zoom *= zoom_factor;
			_camera_zoom = rok::clamp(_camera_zoom, CAMERA_MIN_ZOOM, CAMERA_MAX_ZOOM);
			_view.setSize(static_cast<float>(_window.getSize().x * _camera_zoom),
			              static_cast<float>(_window.getSize().y * _camera_zoom));
		}
	}

	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Num0:
			_simulation.set_speed(Simulation::Speed::PAUSED);
			break;
		case sf::Keyboard::Num1:
			_simulation.set_speed(Simulation::Speed::SPEED_1);
			break;
		case sf::Keyboard::Num2:
			_simulation.set_speed(Simulation::Speed::SPEED_2);
			break;
		case sf::Keyboard::Num3:
			_simulation.set_speed(Simulation::Speed::SPEED_3);
			break;
		case sf::Keyboard::Num4:
			_simulation.set_speed(Simulation::Speed::SPEED_MAX);
			break;
		case sf::Keyboard::Tilde:
			_debug_mode = !_debug_mode;
			break;
		}
	}
}

void GameScene::process_realtime_input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_view.move(static_cast<float>(-CAMERA_SPEED * _camera_zoom), 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_view.move(static_cast<float>(CAMERA_SPEED * _camera_zoom), 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_view.move(0.0f, static_cast<float>(-CAMERA_SPEED * _camera_zoom));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_view.move(0.0f, static_cast<float>(CAMERA_SPEED * _camera_zoom));
	}
}

Scene* GameScene::update() {
	_simulation.check_should_step();
	if (_simulation.should_step()) _simulation.step();

	return this;
}

void GameScene::draw() {
	_window.setView(_view);

	_window.draw(_simulation);

	_window.setView(_window.getDefaultView());

	_step_text.setString("Simulation Speed: " +
	                     std::to_string(static_cast<int>(_simulation.speed())) + "\n" +
	                     "Step " + std::to_string(_simulation.step_number()));
	_step_text.setOrigin(_step_text.getLocalBounds().width, 0.0f);
	_step_text.setPosition(_window.getSize().x - 25.0f, 25.0f);
	_window.draw(_step_text);

	if (_debug_mode) {
		const sf::Vector2f mouse_pos =
			_window.mapPixelToCoords(sf::Mouse::getPosition(_window), _view);

		_debug_text.setString("Mouse Position: " + std::to_string(mouse_pos.x) + ", "
		                                         + std::to_string(mouse_pos.y) + "\n" +
		                      "Camera Zoom: " + std::to_string(_camera_zoom));

		_window.draw(_debug_text);
	}
}
