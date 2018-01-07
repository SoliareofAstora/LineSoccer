#include "Logic.h"



Logic::Logic(): fieldLogic(nullptr)
{
}

void Logic::initialise()
{
	fieldLogic = new FieldLogic();
}

void Logic::update()
{
}


Logic::~Logic()
{
}
