#include "city.hpp"

City::City(const rok::Coordinate coord) :
Feature(rok::CoordinateVector{ coord }) {
	_sprite.setPosition(static_cast<float>(coord.x), static_cast<float>(coord.y));
	_sprite.setSize({ 1.0f, 1.0f });
	_sprite.setFillColor(sf::Color::Black);
}

void City::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}
