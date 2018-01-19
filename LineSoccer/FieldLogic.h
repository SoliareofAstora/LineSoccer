#pragma once
#include "MapNode.h"
#include <SFML/System/Vector2.hpp>
#include "Move.h"
#include <iostream>

namespace sf {
	class Color;
}

class FieldLogic
{
	FieldLogic();
	MapNode **map;
	
	MapNode* GetNode(Move move)
	{
		return &map[move.addrx][move.addry];
	}
	MapNode* GetNode(sf::Vector2i move)
	{
		return &map[move.x][move.y];
	}

public:
	static FieldLogic &instance() { static FieldLogic fieldlogic; return fieldlogic; }
	sf::Vector2i Size;
	sf::Vector2i BallPosition;
	
	void initialise(sf::Vector2i size);

	bool checkIfMoveIsPossible(Move move);
	bool checkIfMoveIsPossible(int direction);

	void saveMove(Move move, sf::Color PlayerColor);
	void saveMove(int direction, sf::Color PlayerColor);

	bool IsMoveFinished();
	void logBallPosition(){ std::cerr << "\nBall position: " << BallPosition.x << " " << BallPosition.y << std::endl; }
	~FieldLogic();
	void Test();
	void reset();
};

