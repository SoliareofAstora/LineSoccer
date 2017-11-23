#pragma once
#include "stack.h"
#include <cstdint>
#include "MapNode.h"


class Player
{
	
public:
	Player() {};
	~Player() {};
	template<typename T>
	stack<int> GetMovement(T *player)
	{
		return player->GetMovement();
	}
};
