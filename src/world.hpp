#pragma once

#include "calendar.hpp"
#include "map.hpp"

class World : public rok::Drawable {
public:
	World();
	virtual ~World() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Map _map;

	Calendar _calendar;
};
