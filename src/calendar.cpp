#include "calendar.hpp"

Calendar::Calendar() :
_step_number(0) {}

void Calendar::step() {
	++_step_number;
}

int Calendar::step_number() const {
	return _step_number;
}
