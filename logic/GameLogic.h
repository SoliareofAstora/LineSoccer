#pragma once
#include <SFML/System/Vector2.hpp>
#include "field/old_FieldLogic.h"
#include "player/AgentLogic.h"

class GameLogic {
  bool playing = true;
 public:
  static GameLogic &instance() {
    static GameLogic logic;
    return logic;
  }
  AgentLogic* agents1;
  AgentLogic* agents2;


  void stopPlaying() { playing = false; }
  GameLogic();
  void mainLoop();
  void initialise();
  void update();
  sf::Vector2i* fieldSize() {
    return &old_FieldLogic::instance().Size;
  }
  ~GameLogic();
};

