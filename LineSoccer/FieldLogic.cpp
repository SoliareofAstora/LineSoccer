#include "FieldLogic.h"
#include "Visualization.h"


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

bool FieldLogic::checkIfMoveIsPossible(Move move)
{
	return GetNode(move)->checkOpen(move.direction);
}

bool FieldLogic::checkIfMoveIsPossible(int direction)
{
	return checkIfMoveIsPossible(Move(BallPosition, direction));
}


void FieldLogic::saveMove(Move move,sf::Color PlayerColor)
{
	GetNode(move)->lockNode(move.direction);
	GetRootNode(move)->allowBounce();
	Visualization::instance().field->drawLine(move.GetSecuredMove(),PlayerColor);
	BallPosition = move.GetDestination();
	logBallPosition();
}

void FieldLogic::saveMove(int direction, sf::Color PlayerColor)
{
	saveMove(Move(BallPosition, direction), PlayerColor);
}

bool FieldLogic::IsMoveFinished()
{
	bool output = !map[BallPosition.x][BallPosition.y].bounce();
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
	srand(time(NULL));
	for (int i = 1; i < Size.x-1; i++)
	{
		for (int j = 1; j < Size.y-1; j++)
		{
			for (uint8_t a = 0; a < 8; a++)
				if (map[i][j].lockNode(a))
				{
					Visualization::instance().field->drawLine(Move(i, j, a).GetSecuredMove(), sf::Color(rand() % 255, rand() % 255, rand() % 255));
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

	//x - kolumny y - rzêy 
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
