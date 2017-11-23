#pragma once
#include <cstdint>
#include "stack.h"
#include <cstdlib>


class RandomAgent
{
	stack<int> movement;
public:
	stack<int> GetMovement();

	RandomAgent();
	~RandomAgent();
};

