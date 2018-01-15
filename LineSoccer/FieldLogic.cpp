#include "FieldLogic.h"
#include "Visualization.h"

void FieldLogic::deleteMap()
{
	if (map != nullptr)
	{
		for (int i = 0; i < Size.x; i++)
		{
			delete[] map[i];
		}
		delete[] map;
	}
}

void FieldLogic::initialiseMap()
{
	map = new MapNode*[Size.x];
	for (int i = 0; i < Size.x; i++)
	{
		map[i] = new MapNode[Size.y];
	}
}

void FieldLogic::refreshNodes()
{
	//TODO do something with it!! Kick it to MapNode.h
	int lockKey[8][4] = {
		{1,2,3,4},
		{1},
		{1,2,3},
		{3,4},
		{2,3,4},
		{4},
		{1,3},
		{1,2}
	};

	for (int j = 0; j < Size.y; j++)
	{
		map[0][j].lock(lockKey[0]);
		if (j != Size.y / 2 && j != Size.y / 2 + 1)
		{
			map[1][j].lock(lockKey[1]);
		}
		map[Size.x - 1][j].lock(lockKey[0]);
	}
	map[0][Size.y / 2].unlock(lockKey[4]);
	map[Size.x - 1][Size.y / 2 - 1].unlock(lockKey[5]);
	map[Size.x - 1][Size.y / 2 + 1].unlock(lockKey[7]);
	map[Size.x - 1][Size.y / 2].unlock(lockKey[6]);
	for (int i = 0; i < Size.x - 1; i++)
	{
		map[i][0].lock(lockKey[2]);
		map[i][Size.y - 1].lock(lockKey[3]);
	}
	map[Size.x - 1][0].lock(lockKey[0]);
}

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

void FieldLogic::reset()
{
	deleteMap();
	initialiseMap();
	refreshNodes();
}

FieldLogic::~FieldLogic()
{
}
