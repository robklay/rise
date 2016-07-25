#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "util/matrix.hpp"
#include "util/sfml_helpers.hpp"
#include "util/types.hpp"

#include "feature.hpp"

enum class Terrain : rok::uint8 {
	OCEAN,
	GRASSLAND,
	HIGHLAND,
};

inline sf::Color terrain_color(const Terrain terrain) {
	switch (terrain) {
	case Terrain::OCEAN:
		return sf::Color(0, 51, 204);
	case Terrain::GRASSLAND:
		return sf::Color(0, 153, 0);
	case Terrain::HIGHLAND:
		return sf::Color(102, 51, 0);
	default:
		assert(false);
	}

	return sf::Color::Black;
}

class Map : public rok::Drawable {
public:
	Map(const rok::Coordinate size = { 0, 0 });
	virtual ~Map() = default;

	rok::Coordinate size() const;

	void set_heightmap(const rok::Matrix<rok::uint32>& matrix);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	using FeaturePtr = std::unique_ptr<Feature>;

	const rok::Coordinate _size;

	rok::Matrix<rok::uint8> _heightmap;
	rok::Matrix<Terrain> _terrain;
	std::vector<FeaturePtr> _features;

	sf::Texture _terrain_texture;
	sf::Sprite _terrain_sprite;
};
