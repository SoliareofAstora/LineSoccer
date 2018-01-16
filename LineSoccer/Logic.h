#pragma once
#include <SFML/System/Vector2.hpp>
#include "FieldLogic.h"

class Logic
{
	bool playing = true;
public:
	static Logic &instance() { static Logic logic; return logic; }
	FieldLogic *fieldLogic;
	void stopPlaying() { playing = false; }
	Logic();
	void mainLoop();
	void initialise();
	void update();
	sf::Vector2i* fieldSize() {
		return &fieldLogic->Size;
	}
	~Logic();
};

