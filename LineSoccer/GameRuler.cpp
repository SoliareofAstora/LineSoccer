#include "GameRuler.h"
#include <SFML/Graphics.hpp>
#include "Debug.cpp"
#include "RandomAgent.h"
#include "Player.h"
#include "Visualization.h"

GameRuler::~GameRuler()
{
	out("GameRuler Destructor...");
	delete window;
	delete visualization;
	delete inputController;
	delete logic;

	outln("Finished!");
	outln("\nGood bye!\n");
	system("PAUSE");
}

void GameRuler::Start()
{
	outln("GameRuler Inicjalization...");
	window = new sf::RenderWindow(sf::VideoMode(400, 400), "Line Coccer Battlefield by Piotr Kucharski");
	visualization = new Visualization;
	inputController = new InputController;
	logic = new Logic;


	RandomAgent agent1;
	LinkedList *linked = agent1.GetMovement();

	delete linked;
	outtab("Window");
	outln("GameRuler Inicjalization Finished!");
}

void GameRuler::Play() 
{
	Start();

	outln("Playing...");
	while (window->isOpen())
	{
		inputController->update(window);
		logic->update();
		visualization->update(window);
	}
	outln("Playing Finished!");
}
