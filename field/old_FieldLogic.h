#pragma once
#include "MapNode.h"
#include <SFML/System/Vector2.hpp>
#include "logic/Move.h"
#include <iostream>

namespace sf{
class Color;
}

class old_FieldLogic {
  old_FieldLogic();
  MapNode** map;

  MapNode* GetNode(Move move) {
    return &map[move.addrx][move.addry];
  }
  MapNode* GetNode(sf::Vector2i move) {
    return &map[move.x][move.y];
  }

 public:
  static old_FieldLogic &instance() {
    static old_FieldLogic fieldlogic;
    return fieldlogic;
  }
  sf::Vector2i Size;
  sf::Vector2i BallPosition;
  sf::Vector2i vBallPosition;

  void initialise(sf::Vector2i size);

  bool checkIfMoveIsPossible(Move move);
  bool checkIfMoveIsPossible(int direction);
  bool vcheck(int direction);
  bool checkIfAllLocked();
  bool vcheckIfAllLocked();
  void saveMove(Move move, sf::Color PlayerColor);
  void saveMove(int direction, sf::Color PlayerColor);
  void vsaveMove(int direction);
  int vdistance();

  bool MoveNotFinished();
  bool vMoveNotFinished();
  bool vunlock(Move direction);
  bool vunlock(int direction);
  bool IsMoveFinished();
  void logBallPosition() { std::cerr << "\nBall position: " << BallPosition.x << " " << BallPosition.y << std::endl; }
  void logvBallPosition() {
    std::cerr << "\nvBall position: " << vBallPosition.x << " " << vBallPosition.y << std::endl;
  }

  ~old_FieldLogic();
  void Test();
  void reset();
};

