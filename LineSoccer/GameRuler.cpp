#include "GameRuler.h"
#include "Visualization.h"

void GameRuler::Start()
{
	Logic::instance().initialise();
	Visualization::instance().initialise();
}

void GameRuler::Play() 
{
	Start();
	while (playing)
	{
		inputController.update();

		Visualization::instance().update();
	}
}

GameRuler::~GameRuler()
{
}
