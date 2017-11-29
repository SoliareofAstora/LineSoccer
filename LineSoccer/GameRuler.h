#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "visualization.h"
#include "InputController.h"
#include "Logic.h"

class GameRuler
{
	GameRuler(){}
	InputController inputController;
	Logic logic;
	

public:

	bool playing = true;
	static GameRuler &instance(){ static GameRuler game; return game; };

	void StopPlaying() { playing = false; }
	void Start();
	void Play();
	~GameRuler();
};

