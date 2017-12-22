#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "settlement.hpp"
#include "map.hpp"

class World : public rok::Drawable {
public:
	World();
	virtual ~World() = default;

	void update();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	const sf::Font& city_font() const { return _city_font; }

private:
	using SettlementUPtr = std::unique_ptr<Settlement>;

	Map _map;
	std::vector<SettlementUPtr> _settlements;

	sf::Font _city_font;
};
