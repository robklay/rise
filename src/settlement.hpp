#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "util/coordinate.hpp"
#include "util/sfml_helpers.hpp"
#include "util/types.hpp"

class World;

class Settlement : public rok::Drawable {
public:
	Settlement(const std::string& name, const rok::Coordinate position,
		const rok::int64 population, const World* world);
	virtual ~Settlement() = default;

	rok::Coordinate position() const;

	void update();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	const World* _world;

	std::string _name;

	const rok::Coordinate _position;

	double _population = 1.0;

	// In percents
	double _birth_rate = 2.0 * (0.04 / 365.0);
	double _death_rate = 0.04 / 365.0;

	sf::RectangleShape _sprite;
	mutable sf::Text _city_text;
};
