#pragma once
#include "logic/FieldLogic.h"
#include "LinkedList.h"
#include <iterator>

class node {
 public:
  int direction;
  node* parent;
  node* childrens[8];

  node():direction(8) {
  }
  node(int dir, node* parent):direction(dir), parent(parent) {

  }
  std::vector<int> generate() {
    std::cerr << "\nGenerate\n";
    std::vector<int> output;
    int closestDistance = 9999999;

    if (FieldLogic::instance().vMoveNotFinished()) {

      for (int i = 0; i < 8; i++) {
        std::cerr << "generating next\n";
        if (FieldLogic::instance().vcheck(i)) {
          std::cerr << "\n next at" + std::to_string(i);
          FieldLogic::instance().vsaveMove(i);
          childrens[i] = new node(i, this);
          std::vector<int> temp = childrens[i]->generate();
          std::cerr << "Wygenerowano\n";
          if (temp.front() < closestDistance) {
            output = temp;
            closestDistance = output.front();
            std::cerr << "\n   zamiana\n";
          }
        }
      }
      std::cerr << "\n";
    } else {
      std::cerr << "\n   generowanie odpowiedzi\n";
      output.push_back(FieldLogic::instance().vdistance());
      node* current = this;
      if (direction != 8) {
        do {
          output.push_back(current->direction);
          current = current->parent;
        } while (current->direction != 8);
      }
    }
    for (int element : output) {
      std::cerr << element << " ";
    }
    std::cerr << "\n   drukowanie\n";
    FieldLogic::instance().vunlock(direction);
    std::cerr << "\n   zwracanie\n";

    return output;
  }
};
