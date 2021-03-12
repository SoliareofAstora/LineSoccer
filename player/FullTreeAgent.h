#pragma once
#include <SFML/Graphics/Color.hpp>
#include "logic/Move.h"
#include "logic/FieldLogic.h"
#include "utils/node.h"

class FullTreeAgent {

 public:
  FullTreeAgent();
  void move(sf::Color color);
  ~FullTreeAgent();
};

