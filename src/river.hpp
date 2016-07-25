#pragma once

#include "feature.hpp"

class River : public Feature {
public:
	River(const rok::CoordinateList& coords);
	virtual ~River() = default;

	virtual void draw(sf::RenderWindow& window) const override;

private:
	sf::Texture _texture;
	sf::Sprite _sprite;
};
