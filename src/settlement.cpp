#include "settlement.hpp"

#include <cmath>

#include "world.hpp"

Settlement::Settlement(const std::string& name, const rok::Coordinate position,
	const rok::int64 population, const World* world)
		: _world(world)
		, _name(name)
		, _position(position)
		, _population(static_cast<double>(population)) {
	_sprite.setPosition(static_cast<float>(position.x), static_cast<float>(position.y));
	_sprite.setSize({ 1.0f, 1.0f });
	_sprite.setFillColor(sf::Color::Black);

	_city_text.setFont(_world->city_font());
	_city_text.setCharacterSize(10);
	_city_text.setColor(sf::Color::Black);
}

rok::Coordinate Settlement::position() const {
	return _position;
}

// TODO: Maybe ensure that a double is 64 bits.
void Settlement::update() {
	const double growth_rate = _birth_rate - _death_rate;
	_population *= std::exp(growth_rate / 100.0);
	//_population *= 1.0 + growth_rate / 100.0;
}

void Settlement::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);

	_city_text.setString(_name + ": Population " + std::to_string(std::lround(_population)));
	_city_text.setOrigin(
		_city_text.getLocalBounds().width / 2.0f,
		_city_text.getLocalBounds().height / 2.0f);
	_city_text.setPosition(
		static_cast<float>(_position.x),
		static_cast<float>(_position.y) - 10.0f);
	target.draw(_city_text, states);
}
