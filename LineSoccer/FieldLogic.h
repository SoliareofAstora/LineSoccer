#pragma once
#include "MapNode.h"
#include <SFML/System/Vector2.hpp>
#include "Move.h"

class FieldLogic
{
	MapNode **map;


public:
	sf::Vector2i Size;

	FieldLogic();
	FieldLogic(sf::Vector2i size);
	bool checkMoveIfPossible(Move move);
	void saveMove(Move move);
	void reset();
	~FieldLogic();
};

