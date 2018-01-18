#include "RandomAgent.h"
#include <ctime>


RandomAgent::RandomAgent()
{
}


void RandomAgent::getMove()
{

}

void RandomAgent::Move()
{
	srand(time(NULL));
	int destination = 0;
	while (!FieldLogic::instance().IsMoveFinished())
	{
		destination = rand() % 8;
		std::cerr <<" "<< destination;
		
		if (FieldLogic::instance().checkIfMoveIsPossible(destination))
		{
			FieldLogic::instance().saveMove(destination, color);
		}
	}
	std::cerr << " \n" << destination<< "  >";
	system("pause");
}

RandomAgent::~RandomAgent()
{
}
