#include "Logic.h"



Logic::Logic(): fieldLogic(nullptr)
{
}

void Logic::initialise()
{
	fieldLogic = new FieldLogic(sf::Vector2i(11,11));
}

void Logic::update()
{
}


Logic::~Logic()
{
}
