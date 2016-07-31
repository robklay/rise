#pragma once

class Calendar {
public:
	Calendar();

	void step();
	int step_number() const;

private:
	int _step_number;
};
