#pragma once

#include "feature.hpp"

class City : public Feature {
public:
	City(const rok::Coordinate coord);
	virtual ~City() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::RectangleShape _sprite;
};
