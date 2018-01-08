#include "GameRuler.h"
#include "Visualization.h"
#include "InputController.h"
#include "Logic.h"
void GameRuler::Start()
{
	InputController::instance().initialise();
	Logic::instance().initialise();
	Visualization::instance().initialise();
}

void GameRuler::Play() 
{
	Start();
	Logic::instance().fieldLogic->reset();
	while (playing)
	{
		InputController::instance().update();

		Visualization::instance().update();
	}
}

GameRuler::~GameRuler()
{
}
