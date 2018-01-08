#include "Logic.h"



Logic::Logic(): fieldLogic(nullptr)
{
}

void Logic::initialise()
{
	fieldLogic = new FieldLogic(sf::Vector2i(150,101));
}

void Logic::update()
{

}


Logic::~Logic()
{
}
