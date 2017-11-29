#include "GameRuler.h"
#include "Visualization.h"

void GameRuler::Start()
{
	Visualization::instance().initialise();
}

void GameRuler::Play() 
{
	Start();
	while (playing)
	{
		inputController.update();
		logic.update();
		Visualization::instance().update();
	}
}

GameRuler::~GameRuler()
{
}
