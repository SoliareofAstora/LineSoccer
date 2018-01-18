#include "Arrows.h"






void Arrows::display(sf::RenderWindow* window)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arrows[i][j].display(window);
		}
	}
}

Arrows::~Arrows()
{
}
