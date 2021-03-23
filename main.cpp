#include "logic/GameLogic.h"

#include "field/field_logic.hpp"
#include <bitset>
#include <iostream>
int main() {

  auto fl = FieldLogic(40, 26);
  fl.print_links();
  fl.close_link(0);
  fl.print_links();

  // GameLogic::instance().mainLoop();
  return 0;
}
