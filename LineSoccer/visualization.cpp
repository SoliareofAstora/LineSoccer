#include "Visualization.h"
#include "Logic.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>


void Visualization::update()
{
	
}

void Visualization::draw()
{
	window->clear();
	field->display(window);
	window->display();
}

void Visualization::resetField()
{
	field->reset(&Logic::instance().logicSize);
}

void Visualization::initialise()
{
	window = new sf::RenderWindow(sf::VideoMode(1001, 1001), "Line Soccer");
	field = new FieldVisualization(
		sf::Vector2f (0,0), 
		sf::Vector2u (1000,1000),
		&Logic::instance().logicSize);
	draw();
}



Visualization::~Visualization()
{
	window->close();
	delete window;
}
