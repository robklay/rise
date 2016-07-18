#include "game_scene.hpp"

GameScene::GameScene(sf::RenderWindow& window) :
Scene(window) {}

void GameScene::process_event(const sf::Event event) {}

void GameScene::process_realtime_input() {}

Scene* GameScene::update() {
	return this;
}

void GameScene::render() {}
