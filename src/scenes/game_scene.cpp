#include "game_scene.hpp"

constexpr double GameScene::CAMERA_SPEED;
constexpr double GameScene::CAMERA_ZOOM_SPEED;
constexpr double GameScene::CAMERA_MIN_ZOOM;
constexpr double GameScene::CAMERA_MAX_ZOOM;

GameScene::GameScene(sf::RenderWindow& window) :
Scene(window),
_map(5632, 2048),
_view(sf::FloatRect(0.0f, 0.0f,
                    static_cast<float>(window.getSize().x),
                    static_cast<float>(window.getSize().y))),
_camera_zoom(1.0f) {
	sf::Image heightmap_image;
	heightmap_image.loadFromFile("data/heightmap.png");
	//_map.set_heightmap(matrix_from_sf_image<rok::int32>(heightmap_image))

	_terrain_texture.loadFromImage(heightmap_image);
	_terrain_sprite.setTexture(_terrain_texture);
}

void GameScene::process_event(const sf::Event event) {
	if (event.type == sf::Event::MouseWheelScrolled) {
		if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
			float zoom_factor =
				1.0f + event.mouseWheelScroll.delta * static_cast<float>(-CAMERA_ZOOM_SPEED);

			if (_camera_zoom * zoom_factor < CAMERA_MIN_ZOOM) {
				zoom_factor = static_cast<float>(_camera_zoom / CAMERA_MIN_ZOOM);
			}
			if (_camera_zoom * zoom_factor > CAMERA_MAX_ZOOM) {
				zoom_factor = static_cast<float>(_camera_zoom / CAMERA_MAX_ZOOM);
			}

			_camera_zoom *= zoom_factor;
			//_camera_zoom = rok::clamp(_camera_zoom, CAMERA_MIN_ZOOM, CAMERA_MAX_ZOOM);
			_view.zoom(zoom_factor);
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

void GameScene::render() {
	_window.setView(_view);
	_window.draw(_terrain_sprite);
}
