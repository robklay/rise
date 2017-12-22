#pragma once

#include <SFML/Graphics.hpp>

#include "util/coordinate.hpp"
#include "util/sfml_helpers.hpp"

class Feature : public rok::Drawable {
public:
	Feature(const rok::Region& region);
	virtual ~Feature() = default;

	bool contains(const rok::Coordinate coord) const;
	const rok::Region region() const;
	int num_coords() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

protected:
	rok::Region _region;
	int _num_coords = 0;
};
