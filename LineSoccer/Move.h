#pragma once
#include <bitset>

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
		if (this->direction > 3)
		{
			if (this->direction > 4)
			{
				this->addrx--;
			}
			if (this->direction == 7)
			{
				this->addry--;
			}
			if (this->direction < 6)
			{
				this->addry++;
			}
			this->direction -= 4;
		}
	}	
};
