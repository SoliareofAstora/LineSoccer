#include "FieldLogic.h"
#include "Visualization.h"
#include "GameLogic.h"
#include <SFML/System/Sleep.hpp>


FieldLogic::FieldLogic(): map(nullptr)
{
}

void FieldLogic::initialise(sf::Vector2i size)
{
	//TODO kick to another function
	size.x += size.x % 2;
	if (size.x<10)
	{
		size.x = 10;
	}
	size.y += 1 - size.y % 2;
	if (size.y<7)
	{
		size.y = 7;
	}
	Size = size;
}

bool FieldLogic::checkIfMoveIsPossible(Move move, bool buul)
{
	sf::Vector2i dest = move.GetDestination();
	if (dest.y<0)
	{
		return false;
	}
	if (dest.y>Size.y - 1)
	{
		return false;
	}
	if (dest.y == Size.y / 2 && (dest.x == Size.x || dest.x == 0))
	{
		Visualization::instance().resetField();
		reset();
		return true;
	}
	if (false)
	{
		if (checkIfAllLocked())
		{
			/*for (int i = 0; i < 1; i++) {

				Visualization::instance().field->drawLine(move, sf::Color::Green);
				sleep(sf::milliseconds(50));
				Visualization::instance().field->drawLine(move, sf::Color::White);
				sleep(sf::milliseconds(50));
			}*/
			for (int i = 0; i<8; i++)
			{
				if (checkIfMoveIsPossible(i, false))
				{
					std::cerr << "PROBLEM!!!";
				}
			}
			system("pause");
			Visualization::instance().resetField();
			reset();
			return true;
		}
	}
	return GetNode(move)->checkOpen(move.direction);
}

bool FieldLogic::checkIfMoveIsPossible(Move move)
{
	return checkIfMoveIsPossible(move, true);
}

bool FieldLogic::checkIfMoveIsPossible(int direction)
{
	return checkIfMoveIsPossible(Move(BallPosition, direction),true);
}

bool FieldLogic::checkIfMoveIsPossible(int direction,bool buul)
{
	return checkIfMoveIsPossible(Move(BallPosition, direction), buul);
}

bool FieldLogic::checkIfAllLocked()
{
	for (int i =0;i<8;i++)
	{
		if (checkIfMoveIsPossible(i,false))
		{
			return false;
		}
	}
	return true;
}


void FieldLogic::saveMove(Move move,sf::Color PlayerColor)
{
	GetNode(move)->lockNode(move.direction);
	GetNode(BallPosition)->allowBounce();
	BallPosition = move.GetDestination();

	Visualization::instance().field->drawLine(move,PlayerColor);
	logBallPosition();
}

void FieldLogic::saveMove(int direction, sf::Color PlayerColor)
{
	saveMove(Move(BallPosition, direction), PlayerColor);
}

bool FieldLogic::MoveNotFinished()
{
	return GetNode(BallPosition)->bounce();
}

bool FieldLogic::IsMoveFinished()
{
	bool output = !GetNode(BallPosition)->bounce();
	if (!output)
	{
		std::cerr << "bounce";
	}
	return output;
}

FieldLogic::~FieldLogic()
{
	if (map != nullptr)
	{
		for (int i = 0; i < Size.x; i++)
		{
			delete[] map[i];
		}
		delete[] map;
	}
}

void FieldLogic::Test()
{
	for (int i = 0; i < Size.x; i++)
	{
		for (int j = 0; j < Size.y; j++)
		{
			for (uint8_t a = 0; a < 4; a++)
				if (map[i][j].checkOpen(a))
				{
					Visualization::instance().field->drawLine(Move(i, j, a), sf::Color::Green);
				}
			Visualization::instance().draw();
		}
	}
}

void FieldLogic::reset()
{
	if (map != nullptr)
	{
		for (int i = 0; i < Size.x; i++)
		{
			delete[] map[i];
		}
		delete[] map;
	}

	map = new MapNode*[Size.x];
	for (int i = 0; i < Size.x; i++)
	{
		map[i] = new MapNode[Size.y];
	}

	//TODO do something with it!! Kick it to MapNode.h
	int lockKey[8][4] = {
		{ 1,2,3,4 },
	{ 1 },
	{ 1,2,3 },
	{ 3,4 },
	{ 2,3,4 },
	{ 4 },
	{ 1,3 },
	{ 1,2 }
	};

	//x - kolumny y - rz�y 
	for (int j = 0; j < Size.y; j++)
	{
		map[0][j].lockMultipleNodes(lockKey[0]);
		if (j != Size.y / 2 && j != Size.y / 2 + 1)
		{
			map[1][j].lockMultipleNodes(lockKey[1]);
		}
		map[Size.x - 1][j].lockMultipleNodes(lockKey[0]);
	}

	map[0][Size.y / 2].unlockMultipleNodes(lockKey[4]);
	map[Size.x - 1][Size.y / 2 - 1].unlockMultipleNodes(lockKey[5]);
	map[Size.x - 1][Size.y / 2 + 1].unlockMultipleNodes(lockKey[7]);
	map[Size.x - 1][Size.y / 2].unlockMultipleNodes(lockKey[6]);
	for (int i = 0; i < Size.x - 1; i++)
	{
		map[i][0].lockMultipleNodes(lockKey[2]);
		map[i][Size.y - 1].lockMultipleNodes(lockKey[3]);
	}
	map[Size.x - 1][0].lockMultipleNodes(lockKey[0]);

	for (int j = 0; j < Size.y; j++)
	{
		if (j != Size.y / 2)
		{
			map[1][j].allowBounce();
			map[Size.x - 1][j].allowBounce();
		}
	}
	for (int j = 0; j < Size.x; j++)
	{
		map[j][0].allowBounce();
		map[j][Size.y - 1].allowBounce();
	}
	map[Size.x / 2][Size.y / 2].allowBounce();
	BallPosition = Size / 2;
	logBallPosition();
	//Test();
}
