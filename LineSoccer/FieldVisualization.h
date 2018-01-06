#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class FieldVisualization
{
	sf::Image image;
	sf::Texture texture;
	sf::Sprite fieldSprite;
	int step;
	void createNodeDots(sf::Vector2u *logicSize);
	void createFieldBorder(sf::Vector2u *logicSize);
	void drawNode(int addrx, int addry);
public:
	FieldVisualization(sf::Vector2f position, sf::Vector2u pixelSize, sf::Vector2u* logicSize);
	void display(sf::RenderWindow *window);
	
	void drawLine(int addrx, int addry, uint8_t direction, sf::Color color);
	~FieldVisualization();
};

