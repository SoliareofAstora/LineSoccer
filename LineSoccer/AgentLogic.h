#pragma once
#include "RandomAgent.h"

class AgentLogic
{
	RandomAgent players[2];
	bool currentplayer = false;
public:
	AgentLogic(){};
	void initialise();
	void update();
	~AgentLogic();
};

