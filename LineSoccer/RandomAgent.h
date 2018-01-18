#pragma once
#include"FieldLogic.h"
#include <SFML/Graphics/Color.hpp>

class RandomAgent
{
	sf::Color color;
public:
	RandomAgent();
	RandomAgent(sf::Color playercolor)
	{
		color = playercolor;
	}
	void getMove();
	void Move();
	~RandomAgent();
};

