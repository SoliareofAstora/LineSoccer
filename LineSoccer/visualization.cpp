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
	window = new sf::RenderWindow(sf::VideoMode(1001, 1001), "Line Soccer");
	field = new FieldVisualization(sf::Vector2f (0,0), sf::Vector2u (1000,1000), sf::Vector2u (101,101));




	/*
	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLine(10, 10, i,sf::Color::Red);
	}

	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLine(11, 10, i, sf::Color::Yellow);
	}
	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLine(10, 11, i, sf::Color::Magenta);
	}
	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLine(11, 11, i, sf::Color::Cyan);
	}
	*/

}

Visualization::~Visualization()
{
	window->close();
	delete window;
}
