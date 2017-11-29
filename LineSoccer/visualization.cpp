#include "Visualization.h"
#include <SFML/Graphics/CircleShape.hpp>

Visualization::~Visualization()
{
	std::cerr << "kasownik\n";
	window->close();
	delete window;
}

void Visualization::update()
{
	int step = 6;
	sf::Vertex line[2];

	line[0].position = sf::Vector2f(200, 200);
	line[0].color = sf::Color::Green;
	line[1].position = sf::Vector2f(200 + step, 200 + step);
	line[1].color = sf::Color::Green;
	sf::Vertex line2[2];

	line2[0].position = sf::Vector2f(200, 200);
	line2[0].color = sf::Color::Green;
	line2[1].position = sf::Vector2f(200 + step, 200);
	line2[1].color = sf::Color::Green;
	sf::Vertex line3[2];

	line3[0].position = sf::Vector2f(200, 200);
	line3[0].color = sf::Color::Green;
	line3[1].position = sf::Vector2f(200, 200 + step);
	line3[1].color = sf::Color::Green;
	sf::Vertex line4[2];

	line4[0].position = sf::Vector2f(200 + step, 200);
	line4[0].color = sf::Color::Red;
	line4[1].position = sf::Vector2f(200, 200 + step);
	line4[1].color = sf::Color::Red;
	sf::Vertex line5[2];

	line3[0].position = sf::Vector2f(200, 200);
	line3[0].color = sf::Color::Black;
	line3[1].position = sf::Vector2f(200, 200 + step);
	line3[1].color = sf::Color::Black;

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	window->clear();
	window->draw(shape);
	window->draw(line, 2, sf::Lines);
	window->draw(line2, 2, sf::Lines);
	window->draw(line3, 2, sf::Lines);
	window->draw(line4, 2, sf::Lines);
	window->draw(line5, 2, sf::Lines);
	window->display();

}

void Visualization::initialise()
{
	window = new sf::RenderWindow(sf::VideoMode(400, 400), "Line Coccer Battlefield by Piotr Kucharski");
	for (int i = 0; i < 100; i++) {}

}


