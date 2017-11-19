#pragma once
#include "stack.h"
#include <cstdint>

template<typename T>
class Player
{

public:
	Player() {};
	~Player() {};
	stack<uint8_t> TakeMovement()
	{
		stack<uint8_t> movement;
		return movement;
	}
};
