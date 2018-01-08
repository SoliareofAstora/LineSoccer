#pragma once
#include <SFML/System/Vector2.hpp>
#include "FieldLogic.h"

class Logic
{
	
public:
	static Logic &instance() { static Logic logic; return logic; }
	FieldLogic *fieldLogic;
	Logic();
	void initialise();
	void update();
	sf::Vector2i* fieldSize() {
		return &fieldLogic->Size;
	}
	~Logic();
};

