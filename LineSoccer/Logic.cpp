#include "Logic.h"



Logic::Logic(): fieldLogic(nullptr)
{

}

void Logic::initialise()
{
	fieldLogic = new FieldLogic(sf::Vector2i(10,10));
}

void Logic::update()
{

}


Logic::~Logic()
{
}
