#include "InputController.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "visualization.h"
#include "GameLogic.h"

void InputController::update()
{
	sf::Event event;
	while (Visualization::instance().getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed
			)
		{
			GameLogic::instance().stopPlaying();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
	//	if (awaitingSpacebar)
		{
			FieldLogic::instance().reset();
			//awaitingSpacebar = false;
		}
	}
	else
	{
		//awaitingSpacebar = true;
	}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			if (FieldLogic::instance().checkIfMoveIsPossible(7))
				FieldLogic::instance().saveMove(7, tempcolor);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			if (FieldLogic::instance().checkIfMoveIsPossible(1))
				FieldLogic::instance().saveMove(1, tempcolor);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (FieldLogic::instance().checkIfMoveIsPossible(6))
				FieldLogic::instance().saveMove(6, tempcolor);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (FieldLogic::instance().checkIfMoveIsPossible(0))
				FieldLogic::instance().saveMove(0, tempcolor);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			if (FieldLogic::instance().checkIfMoveIsPossible(2))
				FieldLogic::instance().saveMove(2, tempcolor);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			if (FieldLogic::instance().checkIfMoveIsPossible(5))
				FieldLogic::instance().saveMove(5, tempcolor);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			if (FieldLogic::instance().checkIfMoveIsPossible(4))
				FieldLogic::instance().saveMove(4, tempcolor);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			if (FieldLogic::instance().checkIfMoveIsPossible(3))
				FieldLogic::instance().saveMove(3, tempcolor);
		}
		if (FieldLogic::instance().IsMoveFinished())
		{
			awaitingSpacebar = !awaitingSpacebar;
			tempcolor = awaitingSpacebar ? sf::Color::Red : sf::Color::White;
		}
}

InputController::InputController()
{
}


InputController::~InputController()
{
}
