//
// Created by soliareofastora on 20.03.2021.
//

#include <iostream>

#include "field/field_logic.hpp"
#include "logic/GameLogic.h"
int main() {
  auto fl = FieldLogic(40, 26);
  fl.reset();
  fl.print_links();

  // GameLogic::instance().mainLoop();
  return 0;
}
