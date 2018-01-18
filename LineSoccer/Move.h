#pragma once
#include <bitset>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Move
{

public:
	int addrx;
	int addry;
	uint8_t direction;

	Move() :addrx(0), addry(0), direction(0){}

	Move(int addrx, int addry, uint8_t direction): addrx(addrx), addry(addry), direction(direction)
	{
		this->direction %= 8;
	}	
	Move(sf::Vector2i addr, uint8_t direction) : addrx(addr.x), addry(addr.y), direction(direction)
	{
		this->direction %= 8;
	}

	int8_t getDirection()
	{
		if (direction > 3)
		{
			return direction - 4;
		}
		return direction;
	}
	sf::Vector2i GetDestination()
	{
		int x = addrx;
		int y = addry;

		if (direction > 4)
		{
			x--;
		}
		if (direction < 4 && direction>0)
		{
			x++;
		}
		if (direction == 7||direction<2)
		{
			y--;
		}
		if (direction < 6 && direction >2)
		{
			y++;
		}
		return sf::Vector2i(x, y);
	}

	Move GetUnchangedMove()
	{
		return *this;
	}

	Move GetSecuredMove()
	{
		Move move(addrx, addry, direction);
		move.checkDirection();
		return move;
	}

	void checkDirection()
	{
		if (direction > 3)
		{

			if (direction > 4)
			{
				addrx--;
			}
			if (direction == 7)
			{
				addry--;
			}
			if (direction < 6)
			{
				addry++;
			}
			direction -= 4;
		}
	}
};
