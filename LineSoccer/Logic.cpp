#include "Logic.h"



Logic::Logic(): fieldLogic(nullptr)
{
}

void Logic::initialise()
{
	fieldLogic = new FieldLogic(sf::Vector2i(50,50));
}

void Logic::update()
{

}


Logic::~Logic()
{
}
