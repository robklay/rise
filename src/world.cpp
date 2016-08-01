#include "world.hpp"

#include "util/sfml_helpers.hpp"

World::World() :
_map({ 5632, 2048 }) {
	sf::Image heightmap_image;
	heightmap_image.loadFromFile("data/heightmap.png");
	_map.set_heightmap(rok::matrix_from_sf_image<rok::uint32>(heightmap_image));
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_map, states);
}
