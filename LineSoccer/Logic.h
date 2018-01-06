#pragma once
#include <SFML/System/Vector2.hpp>

class Logic
{
public:
	sf::Vector2u logicSize;
	static Logic &instance() { static Logic logic; return logic; }

	Logic();
	static void update() {};
	~Logic();
};

