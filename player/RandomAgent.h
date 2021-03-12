#pragma once
#include"logic/FieldLogic.h"
#include <SFML/Graphics/Color.hpp>

class RandomAgent {

 public:
  RandomAgent() {}
  void getMove();
  void Move(sf::Color color);
  ~RandomAgent();
};

