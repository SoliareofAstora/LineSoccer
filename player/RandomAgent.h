#pragma once
#include"field/old_FieldLogic.h"
#include <SFML/Graphics/Color.hpp>

class RandomAgent {

 public:
  RandomAgent() {}
  void getMove();
  void Move(sf::Color color);
  ~RandomAgent();
};

