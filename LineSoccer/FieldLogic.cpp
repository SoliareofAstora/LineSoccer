#include "FieldLogic.h"



FieldLogic::FieldLogic(): map(nullptr)
{
}

FieldLogic::FieldLogic(sf::Vector2u size)
{
	Size = size;
	map = new MapNode*[size.x];
	for (int i = 0; i < size.x;i++)
	{
		map[i] = new MapNode[size.y];
	}
}

void FieldLogic::reset()
{
	if (map!=nullptr)
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
}


FieldLogic::~FieldLogic()
{
}
