#include "sfml_helpers.hpp"

namespace rok {

Color color_from_sf_color(const sf::Color sf_color) {
	return Color(sf_color.r, sf_color.g, sf_color.b, sf_color.a);
}

sf::Color sf_color_from_color(const Color color) {
	return sf::Color(color.r, color.g, color.b, color.a);
}

} // namespace rok
