#include "RandomAgent.h"
#include "Debug.cpp"


stack<int> RandomAgent::GetMovement()
{
	stack<int> temp;
	for (int i = 0; i < 10; i++) {
		int random = rand() / (RAND_MAX / 8);
		temp.push(static_cast<int>(random));
	}
	movement = temp;
	//out(movement);
	return movement;
}

RandomAgent::RandomAgent()
{
}


RandomAgent::~RandomAgent()
{
}
