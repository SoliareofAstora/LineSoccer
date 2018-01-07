#include "Visualization.h"
#include "Logic.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include "FieldLogic.h"


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
	field->reset(Logic::instance().fieldSize());
}

void Visualization::initialise()
{
	window = new sf::RenderWindow(sf::VideoMode(1001, 1001), "Line Soccer");
	field = new FieldVisualization(
		sf::Vector2f (0,0), 
		sf::Vector2i (1000,1000),
		Logic::instance().fieldSize());
	draw();
}



Visualization::~Visualization()
{
	window->close();
	delete window;
}
