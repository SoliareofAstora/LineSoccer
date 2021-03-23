#include "GameLogic.h"
#include "visualization/visualization.h"
#include "input_handler/InputController.h"
#include "input_handler/UI.h"
#include <SFML/System.hpp>

GameLogic::GameLogic() {
}

void GameLogic::mainLoop() {
  initialise();
  old_FieldLogic::instance().reset();

  while (playing) {
//    while (true) {
//      Visualization::instance().draw();
//      sf::sleep(sf::milliseconds(10));
//      InputController::instance().update();
//      Visualization::instance().draw();
//
//      if (!old_FieldLogic::instance().MoveNotFinished()) {
//        std::cerr << "koniec ruchu\n\n";
//        break;
//      }
//    }
    std::cerr << "agent\n";
    //ui.update?
    agents1->update();
    Visualization::instance().draw();
    agents2->update();
    Visualization::instance().draw();
  }
}

void GameLogic::initialise() {
  old_FieldLogic::instance().initialise(sf::Vector2i(100, 100));
  agents1 = new AgentLogic();
  agents2 = new AgentLogic();

  UI::instance().initialise();
  Visualization::instance().initialise();
}

void GameLogic::update() {
}

GameLogic::~GameLogic() {
}
