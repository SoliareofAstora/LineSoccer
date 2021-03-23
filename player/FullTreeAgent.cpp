#include "FullTreeAgent.h"
#include "field/old_FieldLogic.h"
#include "visualization/visualization.h"

FullTreeAgent::FullTreeAgent() {
}

void FullTreeAgent::move(sf::Color color) {
  Node Root = Node();
  std::vector<int> out = Root.generate();
  std::cerr << "FINAL: ";
  for (int element : out) {
    std::cerr << element << " ";
  }
  for (int i = 1; i < out.size(); i++) {
    old_FieldLogic::instance().saveMove(out[i], sf::Color::Red);
  }
  //out.display();









  /*

  int destination = 0;
  while (true)
  {
      destination = 2;
      //std::cerr <<"test "<< destination;

      if (old_FieldLogic::instance().checkIfMoveIsPossible(destination))
      {
          std::cerr << " " << destination;
          old_FieldLogic::instance().saveMove(destination, color);
          Visualization::instance().draw();
      }
      if (!old_FieldLogic::instance().MoveNotFinished())
      {
          std::cerr << "koniec ruchu\n\n";
          break;
      }
  }*/
}

FullTreeAgent::~FullTreeAgent() {
}
