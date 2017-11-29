#include "GameRuler.h"
#include <SFML/Graphics.hpp>
#include "Debug.cpp"
#include "RandomAgent.h"
#include "Player.h"
#include "Visualization.h"

void GameRuler::Start()
{
	Visualization::instance().initialise();
}

void GameRuler::Play() 
{
	Start();
	while (playing)
	{
		inputController.update();
		logic.update();
		Visualization::instance().update();
	}
}

GameRuler::~GameRuler()
{
}
