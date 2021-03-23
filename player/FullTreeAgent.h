#pragma once
#include <SFML/Graphics/Color.hpp>
#include "logic/Move.h"
#include "field/old_FieldLogic.h"
#include "utils/node.h"

class FullTreeAgent {

 public:
  FullTreeAgent();
  void move(sf::Color color);
  ~FullTreeAgent();
};

