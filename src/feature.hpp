#pragma once

#include <SFML/Graphics.hpp>

#include "util/coordinate.hpp"
#include "util/sfml_helpers.hpp"

class Feature : public rok::Drawable {
public:
	Feature(const rok::CoordinateList& coords);
	virtual ~Feature() = default;

	bool contains(const rok::Coordinate coord) const;
	const rok::CoordinateList coords() const;
	int num_coords() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

protected:
	rok::CoordinateList _coords;
	int _num_coords = 0;
};
