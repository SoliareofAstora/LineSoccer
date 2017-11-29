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
	//createFieldBorder(logicSize);
}


void FieldVisualization::display(sf::RenderWindow* window)
{
	texture.update(image);
	fieldSprite.setTexture(texture);
	window->draw(fieldSprite);
}

void FieldVisualization::createNodeDots(sf::Vector2u logicSize)
{
	for (unsigned int i = 2; i < logicSize.x-2; i++)
	{
		for (unsigned int j = 1; j <  logicSize.y-1; j++) {
			image.setPixel(i*step,j*step, sf::Color::White);
		}
	}
	//image.setPixel((logicSize.y / 2)*step, 1 * step, sf::Color::White);
	//image.setPixel((logicSize.y / 2)*step, (logicSize.x-1)*step, sf::Color::White);
}

void FieldVisualization::createFieldBorder(sf::Vector2u logicSize)
{
	for (unsigned int i = 0; i < logicSize.x; i++)
	{
		for (unsigned int j = 0; j < logicSize.y; j++) {
			image.setPixel(i*step, j*step, sf::Color::White);
		}
	}
	for (unsigned int i = 0; i < logicSize.x; i++)
	{
		for (unsigned int j = 0; j < logicSize.y; j++) {
			image.setPixel(i*step, j*step, sf::Color::White);
		}
	}
}


void FieldVisualization::drawLane(int addrx,int addry, uint8_t direction,sf::Color color)
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
