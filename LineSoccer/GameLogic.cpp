#include "GameLogic.h"
#include "Visualization.h"
#include "InputController.h"
#include "UI.h"

GameLogic::GameLogic()
{
}

void GameLogic::mainLoop()
{
	initialise();
	FieldLogic::instance().reset();

	while (playing)
	{
		InputController::instance().update();
		//ui.update?
		//agents->update();
		Visualization::instance().draw();
		system("pause");
	}
}

void GameLogic::initialise()
{
	FieldLogic::instance().initialise(sf::Vector2i(20,30));
	agents = new AgentLogic();
	UI::instance().initialise();
	Visualization::instance().initialise();
}

void GameLogic::update()
{
}


GameLogic::~GameLogic()
{
}
