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
	field = new FieldVisualization(
		sf::Vector2f (0,0), 
		sf::Vector2u (1000,1000),
		new sf::Vector2u (17,11));




	
	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLine(5, 5, i,sf::Color::Red);
	}

	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLine(5, 6, i, sf::Color::Yellow);
	}
	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLine(6, 5, i, sf::Color::Magenta);
	}
	for (uint8_t i = 0; i<4; i++)
	{
		field->drawLine(6, 6, i, sf::Color::Cyan);
	}
	

}

Visualization::~Visualization()
{
	window->close();
	delete window;
}
