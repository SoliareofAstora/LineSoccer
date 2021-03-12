#include "RandomAgent.h"
#include <ctime>
#include <stdlib.h>
#include <SFML/System/Sleep.hpp>
#include <random>
#include "visualization/visualization.h"


void RandomAgent::getMove()
{

}

void RandomAgent::Move(sf::Color color)
{
	
	int destination = 0;
	while (true)
	{
		destination = rand()/(RAND_MAX/8);
		//std::cerr <<"test "<< destination;
		
		if (FieldLogic::instance().checkIfMoveIsPossible(destination))
		{
			std::cerr << " " << destination;
			FieldLogic::instance().saveMove(destination, color);
			Visualization::instance().draw();
		}
		if (!FieldLogic::instance().MoveNotFinished())
		{
			std::cerr << "koniec ruchu\n\n";
			break;
		}
	}
	//std::cerr << " wybrano " << destination<< "  \n";
	//system("pause");
	//sf::sleep(sf::milliseconds(10));
}

RandomAgent::~RandomAgent()
{
}
