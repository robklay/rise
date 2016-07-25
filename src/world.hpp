#pragma once

#include "util/sfml_helpers.hpp"

#include "map.hpp"

class World : public rok::Drawable {
public:
	World();
	virtual ~World() = default;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Map _map;
};
