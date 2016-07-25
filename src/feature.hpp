#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "util/coordinate.hpp"
#include "util/types.hpp"

class Feature {
public:
	Feature(const rok::CoordinateList& coords);
	virtual ~Feature() = default;

	bool contains(const rok::Coordinate coord) const;
	const rok::Coordinate* coords() const;
	int num_coords() const;

	virtual void draw(sf::RenderWindow& window) const = 0;

private:
	rok::CoordinateList _coords;
	int _num_coords;
};
