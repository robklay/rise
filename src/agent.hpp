#pragma once

#include "util/coordinate.hpp"

class Agent {
public:

private:
	AgentController _controller;

	rok::Region _discovered;
	rok::Region _vision;
};

class AgentController {
public:
	virtual ~AgentController() = default;
};
