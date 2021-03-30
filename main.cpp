#include "logic/GameLogic.h"

#include "field/field_logic.hpp"
#include <bitset>
#include <iostream>
int main() {

  auto fl = FieldLogic(40, 26);
//  fl.print_links();
  std::cout<<(int)fl.get_open_links_count();
  fl.close_link(0);
  std::cout<< (int)fl.get_open_links_count();
//  fl.print_links();

  // GameLogic::instance().mainLoop();
  return 0;
}
