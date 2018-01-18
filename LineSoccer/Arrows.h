#pragma once
#include "Arrow.h"

class Arrows
{
	Arrow arrows[3][3];
public:
	Arrows()
	{
		
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arrows[i][j] = Arrow(
					sf::Vector2f(35 + 70 * i, 35 + 70 * j),
					sf::Vector2i(68, 68));
			}
		}
		arrows[1][1].texture.loadFromFile("E:\\Studia\\MySmallProjects\\LineSoccer\\Debug\\Graphic\\ok.png");
		int rot = 0;
		arrows[2][1].rotate(rot * 45); rot++;
		arrows[2][2].rotate(rot * 45); rot++;
		arrows[1][2].rotate(rot * 45); rot++;
		arrows[0][2].rotate(rot * 45); rot++;
		arrows[0][1].rotate(rot * 45); rot++;
		arrows[0][0].rotate(rot * 45); rot++;
		arrows[1][0].rotate(rot * 45); rot++;
		arrows[2][0].rotate(rot * 45); 
	
	
	
	}

	void display(sf::RenderWindow *window);
	~Arrows();
};

