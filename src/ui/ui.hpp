#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "../util/sfml_helpers.hpp"
#include "ui_element.hpp"

class Ui : public rok::Drawable {
public:
	Ui();

	void add_element(UiElement* element);

	void process_event(const sf::Event event);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	using UiElementPtr = std::unique_ptr<UiElement>;

	std::vector<std::unique_ptr<UiElement>> _elements;
};
