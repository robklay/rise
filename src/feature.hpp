#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "util/coordinate.hpp"
#include "util/sfml_helpers.hpp"
#include "util/types.hpp"

class Feature : public rok::Drawable {
public:
	Feature(const rok::CoordinateList& coords);
	virtual ~Feature() = default;

	bool contains(const rok::Coordinate coord) const;
	const rok::Coordinate* coords() const;
	int num_coords() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

private:
	rok::CoordinateList _coords;
	int _num_coords;
};
