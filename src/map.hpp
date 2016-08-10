#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "util/matrix.hpp"
#include "util/sfml_helpers.hpp"
#include "util/types.hpp"

#include "city.hpp"
#include "feature.hpp"

class Map : public rok::Drawable {
public:
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
	using FeaturePtr = std::unique_ptr<Feature>;
	using CityPtr = std::unique_ptr<City>;

	sf::Color terrain_color(const Terrain terrain) const;

	const rok::Coordinate _size;

	// TODO: Consider moving features to World.
	rok::Matrix<rok::uint8> _heightmap;
	rok::Matrix<Terrain> _terrain;
	std::vector<FeaturePtr> _features;

	sf::Texture _terrain_texture;
	sf::Sprite _terrain_sprite;
};
