#pragma once
#include <cstdint>
#include <cstdlib>
#include "LinkedList.h"
#include <iostream>
#include <string>


class RandomAgent
{
public:
	LinkedList* GetMovement()
	{
		LinkedList* ewn= new LinkedList;
		for (int i = 0; i < 10; i++) {

			ewn->push(i);
		}
		return ewn;
	}

	RandomAgent();
	~RandomAgent();
};

