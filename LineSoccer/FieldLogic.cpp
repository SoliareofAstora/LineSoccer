#include "FieldLogic.h"
#include <SFML/Graphics/Color.hpp>
#include <ctime>
#include "Visualization.h"


FieldLogic::FieldLogic(): map(nullptr)
{
}

FieldLogic::FieldLogic(sf::Vector2i size)
{
	Size = size;
}

void FieldLogic::reset()
{
	srand(time(NULL));
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
	/*
	for (int i = 0; i<Size.x; i++)
	{
		if (i==0||i==Size.x-1)
		{
			for (int j = 0; j<Size.y; j++)
			{
				map[i][j].initialise(0);
			}
		}


	}*/



	for (int i=0;i<Size.x;i++)
	{
		for (int j = 1; j<Size.y; j++)
		{
			for (uint8_t a=0;a<4;a++)
			if (map[i][j].lockNode(a))
			{
				Visualization::instance().field->drawLine(i, j, a, sf::Color(rand() % 255, rand() % 255, rand() % 255));
			}
			
		}
		Visualization::instance().draw();
	}
}

FieldLogic::

FieldLogic::~FieldLogic()
{
}
