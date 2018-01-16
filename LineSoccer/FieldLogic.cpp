#include "FieldLogic.h"
#include "Visualization.h"


FieldLogic::FieldLogic(): map(nullptr)
{
}

FieldLogic::FieldLogic(sf::Vector2i size)
{
	//TODO kick to another function
	size.x += size.x % 2;
	if (size.x<10)
	{
		size.x = 10;
	}
	size.y += 1 - size.y % 2;
	if (size.y<7)
	{
		size.y = 7;
	}
	Size = size;
}

//ok, or no
bool FieldLogic::move(int addrx, int addry, uint8_t direction, bool temp)
{
	direction %= 8;
	if (direction > 3)
	{
		if (direction > 4)
		{
			addrx--;
		}
		if (direction == 7)
		{
			addry--;
		}
		if (direction < 6)
		{
			addry++;
		}
		direction -= 4;
	}

	if (map[addrx][addry].checkOpen(direction))
	{
		
	}
	return true;
}

void FieldLogic::reset()
{
	if (map != nullptr)
	{
		for (int i = 0; i < Size.x; i++)
		{
			delete[] map[i];
		}
		delete[] map;
	}

	map = new MapNode*[Size.x];
	for (int i = 0; i < Size.x; i++)
	{
		map[i] = new MapNode[Size.y];
	}

	//TODO do something with it!! Kick it to MapNode.h
	int lockKey[8][4] = {
		{ 1,2,3,4 },
	{ 1 },
	{ 1,2,3 },
	{ 3,4 },
	{ 2,3,4 },
	{ 4 },
	{ 1,3 },
	{ 1,2 }
	};

	for (int j = 0; j < Size.y; j++)
	{
		map[0][j].lockMultiple(lockKey[0]);
		if (j != Size.y / 2 && j != Size.y / 2 + 1)
		{
			map[1][j].lockMultiple(lockKey[1]);
		}
		map[Size.x - 1][j].lockMultiple(lockKey[0]);
	}
	map[0][Size.y / 2].unlockMultiple(lockKey[4]);
	map[Size.x - 1][Size.y / 2 - 1].unlockMultiple(lockKey[5]);
	map[Size.x - 1][Size.y / 2 + 1].unlockMultiple(lockKey[7]);
	map[Size.x - 1][Size.y / 2].unlockMultiple(lockKey[6]);
	for (int i = 0; i < Size.x - 1; i++)
	{
		map[i][0].lockMultiple(lockKey[2]);
		map[i][Size.y - 1].lockMultiple(lockKey[3]);
	}
	map[Size.x - 1][0].lockMultiple(lockKey[0]);
}

FieldLogic::~FieldLogic()
{
}
