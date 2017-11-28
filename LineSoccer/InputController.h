#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class InputController
{
public:
	void update(sf::RenderWindow *window){
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed
				//||event.type == sf::Event::KeyPressed
				)
				window->close();
		}
	}
	InputController();
	~InputController();
};

