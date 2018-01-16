#include "InputController.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "visualization.h"
#include "Logic.h"

void InputController::update()
{
	sf::Event event;
	while (Visualization::instance().getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed
			//||event.type == sf::Event::KeyPressed
		)
		Logic::instance().stopPlaying();
	}
}

InputController::InputController()
{
}


InputController::~InputController()
{
}
