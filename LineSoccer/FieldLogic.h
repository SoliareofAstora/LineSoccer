#pragma once
#include "MapNode.h"
#include <SFML/System/Vector2.hpp>

class FieldLogic
{
	MapNode **map;
public:
	sf::Vector2i Size;

	FieldLogic();
	FieldLogic(sf::Vector2i size);

	void reset();
	~FieldLogic();
};

