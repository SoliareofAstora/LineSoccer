#pragma once
#include <SFML/Graphics/Color.hpp>
#include "Move.h"
#include "FieldLogic.h"
#include "node.h"


class FullTreeAgent
{

public:
	FullTreeAgent();
	void move(sf::Color color);
	~FullTreeAgent();
};

