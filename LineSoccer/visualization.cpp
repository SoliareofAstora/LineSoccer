#include "Visualization.h"

#include <SFML/Graphics/RectangleShape.hpp>


void Visualization::update()
{
	
}

void Visualization::draw()
{
	if (clock.getElapsedTime().asMilliseconds()>NextFrameTime)
	{
		NextFrameTime = clock.getElapsedTime().asMilliseconds() + FrameRate;
		window->clear();
		field->display(window);
		window->display();
	}
}

void Visualization::resetField()
{
	field->reset();
}

void Visualization::initialise()
{
	
	window = new sf::RenderWindow(sf::VideoMode(1001, 1001), "Line Soccer");
	field = new FieldVisualization(
		sf::Vector2f (5,5), 
		sf::Vector2i (800,800));
	draw();
}



Visualization::~Visualization()
{
	window->close();
	delete window;
}
