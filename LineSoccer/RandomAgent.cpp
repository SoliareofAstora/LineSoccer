#include "RandomAgent.h"
#include <ctime>
#include <stdlib.h>
#include <SFML/System/Sleep.hpp>
#include <random>


void RandomAgent::getMove()
{

}

void RandomAgent::Move(sf::Color color)
{
	
	int destination = 0;
	while (FieldLogic::instance().MoveNotFinished())
	{
		destination = rand()/(RAND_MAX/8);
		//std::cerr <<"test "<< destination;
		
		if (FieldLogic::instance().checkIfMoveIsPossible(destination))
		{
			FieldLogic::instance().saveMove(destination, color);
		}
	}
	//std::cerr << " wybrano " << destination<< "  \n";
	//system("pause");
	sf::sleep(sf::milliseconds(10));
}

RandomAgent::~RandomAgent()
{
}
