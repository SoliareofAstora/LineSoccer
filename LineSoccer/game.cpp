#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Debug.cpp"
#include "RandomAgent.h"
#include "Player.h"

Game::Game()
{
	out("Game Constructor...");
	window = new sf::RenderWindow;
	outln("Finished!");
}


Game::~Game()
{
	out("Game Destructor...");
	delete window;

	outln("Finished!");
	outln("\nGood bye!\n");
	system("PAUSE");
}

void Game::Start()
{
	outln("Game Inicjalization...");

	RandomAgent agent1;
	LinkedList *linked = agent1.GetMovement();
	for (int i = 0; i < 10; i++) {

		//	std::cerr << std::to_string(linked->pop()) << " ";
	}
	delete linked;
	window = new sf::RenderWindow(sf::VideoMode(400, 400), "Line Coccer Battlefield by Piotr Kucharski");
	outtab("Window");
	outln("Game Inicjalization Finished!");
}

void Game::Play() const
{
	outln("Playing...");

	while (window->isOpen())
	{
		
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed||
				event.type == sf::Event::KeyPressed)
				window->close();
		}

		window->clear();
		window->draw(shape);
		window->display();
	}
	outln("Playing Finished!");
}
