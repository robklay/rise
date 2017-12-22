#include "world.hpp"

#include "util/sfml_helpers.hpp"

World::World()
		: _map({ 4096, 2048 }) {
	sf::Image heightmap_image;
	heightmap_image.loadFromFile("data/heightmap.png");
	_map.set_heightmap(rok::matrix_from_sf_image<rok::uint32>(heightmap_image));

	_city_font.loadFromFile("data/fonts/roboto.ttf");

	_settlements.emplace_back(new Settlement("Rokbob", { 2558, 894 }, 40'000, this));
	_settlements.emplace_back(new Settlement("Baduga", { 2554, 893 }, 100'000, this));
	//_settlements.emplace_back(new Settlement("Tallinn", { 3190, 325 }, 150, this));
	//_settlements.emplace_back(new Settlement("Helsinki", { 3195, 308 }, 11'000, this));
}

void World::update() {
	for (const SettlementUPtr& c : _settlements) {
		c->update();
	}
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_map, states);

	for (const SettlementUPtr& c : _settlements) {
		target.draw(*c, states);
	}
}
