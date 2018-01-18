#pragma once
#include "Button.h"

class Arrow:public Button
{
public:
	Arrow() {};
	Arrow(sf::Vector2f offset, sf::Vector2i sprSizePx)
		:Button(offset, sprSizePx, "E:\\Studia\\MySmallProjects\\LineSoccer\\Debug\\Graphic\\arrow.png")
	{
		sprite.setOrigin(sprSizePx.x / 2.f, sprSizePx.y / 2.f);
	}
	Arrow(sf::Vector2f offset, sf::Vector2i sprSizePx,float rotation)
		:Button(offset, sprSizePx, "E:\\Studia\\MySmallProjects\\LineSoccer\\Debug\\Graphic\\arrow.png")
	{
		sprite.setOrigin(sprSizePx.x / 2.f, sprSizePx.y / 2.f);
		rotate(rotation);
	}
	void rotate(float rotation)
	{
		sprite.setRotation(rotation);
	}
};
