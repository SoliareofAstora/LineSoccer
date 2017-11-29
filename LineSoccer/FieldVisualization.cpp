#include "FieldVisualization.h"



FieldVisualization::FieldVisualization(sf::Vector2f position, sf::Vector2u spritePxSize, sf::Vector2u logicSize)
{
	fieldSprite.setPosition(position);
	image.create(spritePxSize.x, spritePxSize.y, sf::Color::Black);
	texture.create(spritePxSize.x, spritePxSize.y);
	
	spritePxSize.x /= logicSize.x;
	spritePxSize.y /= logicSize.y;
	spritePxSize.x -= logicSize.x%2;
	spritePxSize.y -= logicSize.y%2;
	step = std::min(spritePxSize.x, spritePxSize.y);

	createNodeDots(logicSize);
	createFieldBorder(logicSize);
}


void FieldVisualization::display(sf::RenderWindow* window)
{
	texture.update(image);
	fieldSprite.setTexture(texture);
	window->draw(fieldSprite);
}

void FieldVisualization::createNodeDots(sf::Vector2u logicSize)
{
	for (unsigned int i = 1; i < logicSize.x - 1; i++)
	{
		for (unsigned int j = 0; j < logicSize.y; j++) {
			drawPixel(i, j);
		}
	}
}

void FieldVisualization::createFieldBorder(sf::Vector2u logicSize)
{
	for (unsigned int i = 0; i < logicSize.x - 1; i++)
	{
		if (i==0||i==logicSize.x-2)
		{
			drawLine(i, (logicSize.y / 2) - 1, 2, sf::Color::White);
			drawLine(i, (logicSize.y / 2) + 1, 2, sf::Color::White);
		}
		else {
			drawLine(i, 0, 2, sf::Color::White);
			drawLine(i, logicSize.y - 1, 2, sf::Color::White);
		}
	}
	for (unsigned int i = 1; i < logicSize.y; i++)
	{
		if (i > (logicSize.y / 2) - 1 && i < (logicSize.y / 2) + 2)
		{
			drawPixel(0, i);
			drawPixel(logicSize.x - 1, i);
			drawLine(0, i, 0, sf::Color::White);
			drawLine(logicSize.x - 1, i, 0, sf::Color::White);
		}
		else
		{
			drawLine(1, i, 0, sf::Color::White);
			drawLine(logicSize.x - 2, i, 0, sf::Color::White);
		}
	}	
	drawPixel(0, (logicSize.y / 2) - 1);
	drawPixel(logicSize.x - 1, (logicSize.y / 2) - 1);
}

void FieldVisualization::createGates(sf::Vector2u logicSize)
{
	
	for (unsigned int i = (logicSize.y / 2) - 1; i < (logicSize.y / 2) + 2; i++)
	{
		
	}
	
}

void FieldVisualization::drawPixel(int addrx, int addry)
{
	image.setPixel(addrx*step,addry*step, sf::Color::White);
}


void FieldVisualization::drawLine(int addrx,int addry, uint8_t direction,sf::Color color)
{
	int x = addrx * step;
	int y = addry * step;
	int dx = 0;
	int dy = 0;

	if (direction >0)
	{
		dx = 1;
	}

	if (direction < 2)
	{
		dy = -1;
	}
	if (direction == 3)
	{
		dy = 1;
	}


	for (uint8_t i=1;i<step;i++)
	{
		x += dx;
		y += dy;
		image.setPixel(x, y, color);
	}
}


FieldVisualization::~FieldVisualization()
{
}
