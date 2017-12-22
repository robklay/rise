#include "ui.hpp"

Ui::Ui() {}

void Ui::add_element(UiElement* element) {
	_elements.emplace_back(element);
}

void Ui::process_event(const sf::Event event) {
	for (UiElementPtr& element : _elements) {
		element->process_event(event);
	}
}

void Ui::draw(sf::RenderTarget& target, sf::RenderStates states) const {

}
