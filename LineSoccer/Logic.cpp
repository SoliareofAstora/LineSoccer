#include "Logic.h"
#include "Visualization.h"
#include "InputController.h"

Logic::Logic(): fieldLogic(nullptr)
{

}

void Logic::mainLoop()
{
	initialise();
	fieldLogic->reset();

	while (playing)
	{
		InputController::instance().update();
		Visualization::instance().draw();
	}
}

void Logic::initialise()
{
	fieldLogic = new FieldLogic(sf::Vector2i(10,10));
	InputController::instance().initialise();

	Visualization::instance().initialise();
}

void Logic::update()
{

}


Logic::~Logic()
{
}
