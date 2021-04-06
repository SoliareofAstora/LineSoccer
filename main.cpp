//
// Created by soliareofastora on 20.03.2021.
//

#include "field_logic.hpp"

int main() {
  auto fl = FieldLogic(2, 2);
  fl.reset();
  fl.print_links();

  for (int i = 0; i < 5; i++) {
    fl.move(6);
    fl.print_links();
  }
  fl.reset();
  fl.print_links();

  for (int i = 0; i < 5; i++) {
    fl.move(2);
    fl.print_links();
  }

  return 0;
}
