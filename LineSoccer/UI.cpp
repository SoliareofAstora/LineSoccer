#include "UI.h"
#include "InputController.h"


UI::UI()
{
}


void UI::initialise()
{
	InputController::instance().initialise();
}

void UI::display(sf::RenderWindow* window)
{
	arrows.display(window);
}

UI::~UI()
{
}
