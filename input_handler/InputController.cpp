#include "InputController.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "visualization/visualization.h"
#include "logic/GameLogic.h"

void InputController::update() {
  sf::Event event;
  while (Visualization::instance().getWindow()->pollEvent(event)) {
    if (event.type == sf::Event::Closed
        ) {
      GameLogic::instance().stopPlaying();
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    //	if (awaitingSpacebar)
    {
      old_FieldLogic::instance().reset();
      Visualization::instance().resetField();
      //awaitingSpacebar = false;
    }
  } else {
    //awaitingSpacebar = true;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
    if (old_FieldLogic::instance().checkIfMoveIsPossible(7))
      old_FieldLogic::instance().saveMove(7, tempcolor);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
    if (old_FieldLogic::instance().checkIfMoveIsPossible(1))
      old_FieldLogic::instance().saveMove(1, tempcolor);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    if (old_FieldLogic::instance().checkIfMoveIsPossible(6))
      old_FieldLogic::instance().saveMove(6, tempcolor);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    if (old_FieldLogic::instance().checkIfMoveIsPossible(0))
      old_FieldLogic::instance().saveMove(0, tempcolor);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    if (old_FieldLogic::instance().checkIfMoveIsPossible(2))
      old_FieldLogic::instance().saveMove(2, tempcolor);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
    if (old_FieldLogic::instance().checkIfMoveIsPossible(5))
      old_FieldLogic::instance().saveMove(5, tempcolor);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
    if (old_FieldLogic::instance().checkIfMoveIsPossible(4))
      old_FieldLogic::instance().saveMove(4, tempcolor);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
    if (old_FieldLogic::instance().checkIfMoveIsPossible(3))
      old_FieldLogic::instance().saveMove(3, tempcolor);
  }
  /*if (old_FieldLogic::instance().IsMoveFinished())
  {
      awaitingSpacebar = !awaitingSpacebar;
      tempcolor = awaitingSpacebar ? sf::Color::White : sf::Color::White;
  }*/
}

InputController::InputController() {
}

InputController::~InputController() {
}
