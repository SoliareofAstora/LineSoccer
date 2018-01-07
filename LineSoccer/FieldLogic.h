#pragma once
#include "MapNode.h"
#include <SFML/System/Vector2.hpp>

class FieldLogic
{
	MapNode **map;
public:
	sf::Vector2u Size;
	static FieldLogic &instance() { static FieldLogic fieldLogic; return fieldLogic; }

	FieldLogic();
	FieldLogic(sf::Vector2u size);

	void reset();
	~FieldLogic();
};

