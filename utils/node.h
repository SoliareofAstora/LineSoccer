#pragma once
#include "field/old_FieldLogic.h"
#include "LinkedList.h"
#include <iterator>

class Node {
 public:
  int direction;
  Node* parent;
  Node* childrens[8];

  Node():direction(8) {
  }
  Node(int dir, Node* parent):direction(dir), parent(parent) {

  }
  std::vector<int> generate() {
    std::cerr << "\nGenerate\n";
    std::vector<int> output;
    int closestDistance = 9999999;

    if (old_FieldLogic::instance().vMoveNotFinished()) {

      for (int i = 0; i < 8; i++) {
        std::cerr << "generating next\n";
        if (old_FieldLogic::instance().vcheck(i)) {
          std::cerr << "\n next at" + std::to_string(i);
          old_FieldLogic::instance().vsaveMove(i);
          childrens[i] = new Node(i, this);
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
      output.push_back(old_FieldLogic::instance().vdistance());
      Node* current = this;
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
    old_FieldLogic::instance().vunlock(direction);
    std::cerr << "\n   zwracanie\n";

    return output;
  }
};
