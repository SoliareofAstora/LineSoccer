#include "AgentLogic.h"



AgentLogic::AgentLogic()
{
}

void AgentLogic::initialise()
{
	players[0] = RandomAgent(sf::Color::Red);
	players[1] = RandomAgent(sf::Color::White);
}


void AgentLogic::update()
{
	currentplayer = !currentplayer;
	players[currentplayer ? 0 : 1].Move();
}

AgentLogic::~AgentLogic()
{
}
