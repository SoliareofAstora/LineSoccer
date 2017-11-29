#include "Visualization.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>


void Visualization::update()
{
	int step = 6;
	sf::Vertex line[2];

	window->clear();
	



	field->display(window);
	
	



	window->display();
}

void Visualization::initialise()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 800), "Line Soccer");
	field = new FieldVisualization(sf::Vector2f (10,10), sf::Vector2u (400,400), sf::Vector2u (50,20));
	/*
	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLane(10, 10, i,sf::Color::Red);
	}

	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLane(11, 10, i, sf::Color::Yellow);
	}
	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLane(10, 11, i, sf::Color::Magenta);
	}
	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLane(11, 11, i, sf::Color::Cyan);
	}
	*/

}

Visualization::~Visualization()
{
	window->close();
	delete window;
}
