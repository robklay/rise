#include "river.hpp"

River::River(const rok::Region& region)
	: Feature(region) {
	const rok::Coordinate min = region.min();
	const rok::Coordinate max = region.max();

	sf::Image image;
	image.create(max.x - min.x + 1, max.y - min.y + 1);
	for (const rok::Coordinate& c : region.coords_vector()) {
		image.setPixel(c.x - min.x, c.y - min.y, sf::Color::Blue);
	}

	_texture.loadFromImage(image);
	_sprite.setTexture(_texture);
	_sprite.setPosition(static_cast<float>(min.x), static_cast<float>(min.y));
}

void River::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}
