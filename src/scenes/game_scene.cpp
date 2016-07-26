#include "game_scene.hpp"

#include "../util/math.hpp"
#include "../util/sfml_helpers.hpp"

constexpr double GameScene::CAMERA_SPEED;
constexpr double GameScene::CAMERA_ZOOM_SPEED;
constexpr double GameScene::CAMERA_MIN_ZOOM;
constexpr double GameScene::CAMERA_MAX_ZOOM;

GameScene::GameScene(sf::RenderWindow& window) :
Scene(window),
_camera_zoom(CAMERA_DEFAULT_ZOOM),
_view(sf::FloatRect(0.0f, 0.0f,
                    static_cast<float>(window.getSize().x * _camera_zoom),
                    static_cast<float>(window.getSize().y * _camera_zoom))) {}

void GameScene::process_event(const sf::Event event) {
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
	return this;
}

void GameScene::draw() {
	_window.setView(_view);
	_window.draw(_world);
}
