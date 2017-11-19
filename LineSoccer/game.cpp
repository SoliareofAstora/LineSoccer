#include "Game.h"
#include <SFML/Graphics.hpp>
#include "Debug.cpp"

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

	window = new sf::RenderWindow(sf::VideoMode(400, 400), "Line Coccer by Piotr Kucharski");
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
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		window->draw(shape);
		window->display();
	}
	outln("Playing Finished!");
}
