#include "GameLogic.h"
#include "Visualization.h"
#include "InputController.h"

GameLogic::GameLogic(): fieldLogic(nullptr)
{

}

void GameLogic::mainLoop()
{
	initialise();
	fieldLogic->reset();

	while (playing)
	{
		InputController::instance().update();
		Visualization::instance().draw();
	}
}

void GameLogic::initialise()
{
	fieldLogic = new FieldLogic(sf::Vector2i(10,10));
	InputController::instance().initialise();

	Visualization::instance().initialise();
}

void GameLogic::update()
{

}


GameLogic::~GameLogic()
{
}
