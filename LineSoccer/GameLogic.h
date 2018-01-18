#pragma once
#include <SFML/System/Vector2.hpp>
#include "FieldLogic.h"
#include "AgentLogic.h"

class GameLogic
{
	bool playing = true;
public:
	static GameLogic &instance() { static GameLogic logic; return logic; }
	AgentLogic *agents;

	void stopPlaying() { playing = false; }
	GameLogic();
	void mainLoop();
	void initialise();
	void update();
	sf::Vector2i* fieldSize() {
		return &FieldLogic::instance().Size;
	}
	~GameLogic();
};

