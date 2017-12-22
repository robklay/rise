#include "ui_element.hpp"

UiElement::UiElement()
	: parent(nullptr)
	, _pos_percent_x(0.0)
	, _pos_percent_y(0.0)
	, _size_percent_x(0.0)
	, _size_percent_y(0.0) {}

void UiElement::add_child(UiElement* element) {
	element->parent = this;
	_children.emplace_back(element);
}

void UiElement::process_event(const sf::Event event) {

}
