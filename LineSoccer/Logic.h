#pragma once
#include <SFML/System/Vector2.hpp>
#include "FieldLogic.h"

class Logic
{
	FieldLogic *fieldLogic;
public:
	static Logic &instance() { static Logic logic; return logic; }

	Logic();
	void initialise();
	void update();
	~Logic();
};

