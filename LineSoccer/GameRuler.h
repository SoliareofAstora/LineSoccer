#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "visualization.h"
#include "InputController.h"
#include "Logic.h"

class GameRuler
{
	GameRuler(){}
	Visualization *visualization;
	InputController *inputController;
	Logic *logic;
	sf::RenderWindow* window;

public:
	
	static GameRuler &instance(){ static GameRuler game; return game; };

	~GameRuler();
	void Start();
	void Play();
};

