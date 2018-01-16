#pragma once
#include "Button.h"

class Arrows
{
	Button buttons[3][3];
public:
	Arrows()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				buttons[i][j]=Button(sf::Vector2f(1+30*i,1+30*j),sf::Vector2i(28,28));
			}
		}
	}
	void display(sf::RenderWindow *window);
	~Arrows();
};

