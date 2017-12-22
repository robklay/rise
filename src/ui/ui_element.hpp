#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "../util/vector2.hpp"

class UiElement {
public:
	UiElement();

	void add_child(UiElement* element);

	void process_event(const sf::Event event);

	const UiElement* parent;

private:
	std::vector<std::unique_ptr<UiElement>> _children;

	rok::Vector2<double> _position;
	bool _pos_percent_x;
	bool _pos_percent_y;

	rok::Vector2<double> _size;
	bool _size_percent_x;
	bool _size_percent_y;
};
