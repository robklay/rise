#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "util/matrix.hpp"
#include "util/sfml_helpers.hpp"
#include "util/types.hpp"

//#include "settlement.hpp"
//#include "feature.hpp"

class Map : public rok::Drawable {
public:
	enum class MapMode {
		TERRAIN,
		POLITICAL,
	};

	enum class Terrain : rok::uint8 {
		OCEAN,
		GRASSLAND,
		HIGHLAND,
	};

	Map() = default;
	Map(const rok::Coordinate size);
	virtual ~Map() = default;

	rok::Coordinate size() const;

	void set_heightmap(const rok::Matrix<rok::uint32>& matrix);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	const rok::Coordinate _size;
	MapMode _map_mode;

	rok::Matrix<rok::uint8> _heightmap;

	rok::Matrix<Terrain> _terrain;
	rok::Matrix<rok::uint16> _owner;

	sf::Texture _terrain_texture;
	sf::Texture _political_texture;
	sf::Sprite _terrain_sprite;
	sf::Sprite _political_sprite;
};
