#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>


class Button
{
	sf::Sprite sprite;
public:
	Button() {};
	Button(sf::Vector2f offset, sf::Vector2i sprSizePx)
	{
		sprite.setPosition(offset);
		sf::Image image;
		image.create(sprSizePx.x, sprSizePx.y, sf::Color::White);
		sf::Texture texture;
		texture.create(sprSizePx.x, sprSizePx.y);
		texture.update(image);
		sprite.setTexture(texture);
	}
	void display(sf::RenderWindow *window) { window->draw(sprite); }
};
