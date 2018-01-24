#include "AgentLogic.h"
#include <ctime>
#include "Visualization.h"


void AgentLogic::initialise()
{
	srand(time(NULL));
	//players[0] = RandomAgent();
	//players[1] = RandomAgent();
	
}


void AgentLogic::update()
{
	//currentplayer = currentplayer;
	//players[currentplayer ? 0 : 1].Move(currentplayer ? sf::Color::Red : sf::Color::Cyan);
	agent.move(sf::Color::Red);
	Visualization::instance().draw();
}

AgentLogic::~AgentLogic()
{
}
