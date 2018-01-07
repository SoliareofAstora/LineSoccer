#include "FieldVisualization.h"

FieldVisualization::FieldVisualization(sf::Vector2f pos, sf::Vector2i sprSizePx, sf::Vector2i* logicSize)
{
	fieldSprite.setPosition(pos);
	image.create(sprSizePx.x, sprSizePx.y, sf::Color::Black);
	texture.create(sprSizePx.x, sprSizePx.y);

	reset(logicSize);
}

void FieldVisualization::display(sf::RenderWindow* window)
{
	texture.update(image);
	fieldSprite.setTexture(texture);
	window->draw(fieldSprite);
}

void FieldVisualization::reset(sf::Vector2i* logicSize)
{
	auto spritePxSize = image.getSize();

	spritePxSize.x /= logicSize->x;
	spritePxSize.y /= logicSize->y;
	spritePxSize.x -= logicSize->x % 2;
	spritePxSize.y -= logicSize->y % 2;
	step = std::min(spritePxSize.x, spritePxSize.y);

	createNodeDots(logicSize);
	createFieldBorder(logicSize);
}

void FieldVisualization::createNodeDots(sf::Vector2i* logicSize)
{
	for (unsigned int i = 1; i < logicSize->x - 1; i++)
	{
		for (unsigned int j = 0; j < logicSize->y; j++)
		{
			drawNode(i, j);
		}
	}
	image.setPixel(logicSize->x / 2 * step, logicSize->y / 2 * step, sf::Color::Red);
}

void FieldVisualization::createFieldBorder(sf::Vector2i* logicSize)
{
	for (unsigned int i = 0; i < logicSize->x - 1; i++)
	{
		if (i == 0 || i == logicSize->x - 2)
		{
			drawLine(i, (logicSize->y / 2) - 1, 2, sf::Color::White);
			drawLine(i, (logicSize->y / 2) + 1, 2, sf::Color::White);
		}
		else
		{
			drawLine(i, 0, 2, sf::Color::White);
			drawLine(i, logicSize->y - 1, 2, sf::Color::White);
		}
	}
	for (unsigned int i = 1; i < logicSize->y; i++)
	{
		if (i > (logicSize->y / 2) - 1 && i < (logicSize->y / 2) + 2)
		{
			drawNode(0, i);
			drawNode(logicSize->x - 1, i);
			drawLine(0, i, 0, sf::Color::White);
			drawLine(logicSize->x - 1, i, 0, sf::Color::White);
		}
		else
		{
			drawLine(1, i, 0, sf::Color::White);
			drawLine(logicSize->x - 2, i, 0, sf::Color::White);
		}
	}
	drawNode(0, (logicSize->y / 2) - 1);
	drawNode(logicSize->x - 1, (logicSize->y / 2) - 1);
}

void FieldVisualization::drawNode(int addrx, int addry)
{
	image.setPixel(addrx * step, addry * step, sf::Color::White);
}

void FieldVisualization::drawLine(int addrx, int addry, uint8_t direction, sf::Color color)
{
	direction %= 8;
	if (direction > 3)
	{
		if (direction > 4)
		{
			addrx--;
		}
		if (direction == 7)
		{
			addry--;
		}
		if (direction < 6)
		{
			addry++;
		}
		direction -= 4;
	}
	int x = addrx * step;
	int y = addry * step;
	int dx = 0;
	int dy = 0;

	if (direction > 0)
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


	for (uint8_t i = 1; i < step; i++)
	{
		x += dx;
		y += dy;
		image.setPixel(x, y, color);
	}
}


FieldVisualization::~FieldVisualization()
{
}
