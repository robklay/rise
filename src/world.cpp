#include "world.hpp"

#include "util/sfml_helpers.hpp"

World::World() :
_map({ 5632, 2048 }) {
	sf::Image heightmap_image;
	heightmap_image.loadFromFile("data/heightmap.png");
	_map.set_heightmap(rok::matrix_from_sf_image<rok::uint32>(heightmap_image));

	_city_font.loadFromFile("data/fonts/roboto.ttf");

	_cities.emplace_back(new City("Riga", { 3183, 379 }, 1'900, this));
	_cities.emplace_back(new City("Saint Petersburg", { 3278, 314 }, 100'000, this));
	_cities.emplace_back(new City("Tallinn", { 3190, 325 }, 150, this));
	_cities.emplace_back(new City("Helsinki", { 3195, 308 }, 11'000, this));
}

void World::update() {
	for (const CityUPtr& c : _cities) {
		c->update();
	}
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_map, states);

	for (const CityUPtr& c : _cities) {
		target.draw(*c, states);
	}
}
