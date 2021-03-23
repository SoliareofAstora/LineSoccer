#include "logic/GameLogic.h"

#include "field/field_logic.hpp"
#include <bitset>
#include <iostream>
int main() {

  auto fl = FieldLogic(26, 15);
  auto bits = fl._links;
  for (int j = 0; j < 15; ++j) {
    for (int i = 0; i < 26; ++i) {
      auto tmp = std::bitset<4>();
      for (int k = 0; k < 4; k++)
        tmp[k] = bits->get_bit((i + j * 26) * 4 + k);
      if (tmp.to_ulong() < 10)
        std::cout << tmp.to_ulong() << "  ";
      else
        std::cout << tmp.to_ulong() << " ";
    }
    std::cout << '\n';
  }
  // GameLogic::instance().mainLoop();

  return 0;
}
