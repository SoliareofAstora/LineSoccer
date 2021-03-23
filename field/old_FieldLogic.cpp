#include "old_FieldLogic.h"
#include "visualization/visualization.h"
#include "logic/GameLogic.h"
#include <SFML/System/Sleep.hpp>
#include <math.h>

old_FieldLogic::old_FieldLogic():map(nullptr) {
}

void old_FieldLogic::initialise(sf::Vector2i size) {
  //TODO kick to another function
  size.x += size.x % 2;
  if (size.x < 10) {
    size.x = 10;
  }
  size.y += 1 - size.y % 2;
  if (size.y < 7) {
    size.y = 7;
  }
  Size = size;
}

bool old_FieldLogic::checkIfMoveIsPossible(Move move) {
  sf::Vector2i dest = move.GetDestination();
  if (dest.y < 0) {
    return false;
  }
  if (dest.y > Size.y - 1) {
    return false;
  }
  if (dest.y == Size.y / 2 && (dest.x == Size.x || dest.x == 0)) {
    Visualization::instance().resetField();
    reset();
    return true;
  }
  return GetNode(move)->checkOpen(move.direction);
}

bool old_FieldLogic::checkIfMoveIsPossible(int direction) {
  return checkIfMoveIsPossible(Move(BallPosition, direction));
}

bool old_FieldLogic::vcheck(int direction) {
  Move move = Move(vBallPosition, direction);
  sf::Vector2i dest = move.GetDestination();
  if (dest.y < 0) {
    return false;
  }
  if (dest.y > Size.y - 1) {
    return false;
  }
  if (dest.y == Size.y / 2 && (dest.x == Size.x || dest.x == 0)) {
    Visualization::instance().resetField();
    reset();
    return true;
  }
  return GetNode(move)->vcheckOpen(move.direction);
}

bool old_FieldLogic::checkIfAllLocked() {
  for (int i = 0; i < 8; i++) {
    if (checkIfMoveIsPossible(i)) {
      return false;
    }
  }
  return true;
}

bool old_FieldLogic::vcheckIfAllLocked() {
  for (int i = 0; i < 8; i++) {
    if (vcheck(i)) {
      return false;
    }
  }
  return true;
}

void old_FieldLogic::saveMove(Move move, sf::Color PlayerColor) {
  GetNode(move)->lockNode(move.direction);
  GetNode(BallPosition)->allowBounce();
  BallPosition = move.GetDestination();
  vBallPosition = BallPosition;
  Visualization::instance().field->drawLine(move, PlayerColor);
  logBallPosition();
}

void old_FieldLogic::saveMove(int direction, sf::Color PlayerColor) {
  saveMove(Move(BallPosition, direction), PlayerColor);
}

void old_FieldLogic::vsaveMove(int direction) {
  Move move = Move(vBallPosition, direction);
  GetNode(move)->vlockNode(move.direction);
  vBallPosition = move.GetDestination();
  logvBallPosition();
}

int old_FieldLogic::vdistance() {
  return (pow(vBallPosition.y - (Size.y / 2), 2) + pow(vBallPosition.x, 2));
}

bool old_FieldLogic::MoveNotFinished() {
  if (checkIfAllLocked()) {
    Visualization::instance().resetField();
    reset();
    return true;
  }
  bool temp = GetNode(BallPosition)->bounce();
  GetNode(BallPosition)->allowBounce();
  return temp;
}

bool old_FieldLogic::vMoveNotFinished() {
  /*if (vcheckIfAllLocked())
  {
      return true;
  }*/
  bool temp = GetNode(vBallPosition)->bounce();
  return temp;
}

bool old_FieldLogic::vunlock(int direction) {
  if (direction > 7) {
    return false;
  }
  Move move = Move(vBallPosition, direction + 4);
  GetNode(move.GetSource())->disableBounce();
  GetNode(move)->vunlockNode(move.direction);
  vBallPosition = move.GetSource();

  return true;
}

bool old_FieldLogic::vunlock(Move move) {

  GetNode(move)->vunlockNode(move.direction);
  vBallPosition = move.GetSource();

  return true;
}

bool old_FieldLogic::IsMoveFinished() {
  bool output = !GetNode(BallPosition)->bounce();
  if (!output) {
    //std::cerr << "bounce";
  }
  return output;
}

old_FieldLogic::~old_FieldLogic() {
  if (map != nullptr) {
    for (int i = 0; i < Size.x; i++) {
      delete[] map[i];
    }
    delete[] map;
  }
}

void old_FieldLogic::Test() {
  for (int i = 0; i < Size.x; i++) {
    for (int j = 0; j < Size.y; j++) {
      for (uint8_t a = 0; a < 4; a++)
        if (map[i][j].checkOpen(a)) {
          Visualization::instance().field->drawLine(Move(i, j, a), sf::Color::Green);
        }
      Visualization::instance().draw();
    }
  }
}

void old_FieldLogic::reset() {
  if (map != nullptr) {
    for (int i = 0; i < Size.x; i++) {
      delete[] map[i];
    }
    delete[] map;
  }

  map = new MapNode* [Size.x];
  for (int i = 0; i < Size.x; i++) {
    map[i] = new MapNode[Size.y];
  }

  //TODO do something with it!! Kick it to MapNode.h
  int lockKey[8][4] = {
      {1, 2, 3, 4},
      {1},
      {1, 2, 3},
      {3, 4},
      {2, 3, 4},
      {4},
      {1, 3},
      {1, 2}
  };

  //x - kolumny y - rz�y
  for (int j = 0; j < Size.y; j++) {
    map[0][j].lockMultipleNodes(lockKey[0]);
    if (j != Size.y / 2 && j != Size.y / 2 + 1) {
      map[1][j].lockMultipleNodes(lockKey[1]);
    }
    map[Size.x - 1][j].lockMultipleNodes(lockKey[0]);
  }

  map[0][Size.y / 2].unlockMultipleNodes(lockKey[4]);
  map[Size.x - 1][Size.y / 2 - 1].unlockMultipleNodes(lockKey[5]);
  map[Size.x - 1][Size.y / 2 + 1].unlockMultipleNodes(lockKey[7]);
  map[Size.x - 1][Size.y / 2].unlockMultipleNodes(lockKey[6]);
  for (int i = 0; i < Size.x - 1; i++) {
    map[i][0].lockMultipleNodes(lockKey[2]);
    map[i][Size.y - 1].lockMultipleNodes(lockKey[3]);
  }
  map[Size.x - 1][0].lockMultipleNodes(lockKey[0]);

  for (int j = 0; j < Size.y; j++) {
    if (j != Size.y / 2) {
      map[1][j].allowBounce();
      map[Size.x - 1][j].allowBounce();
    }
  }
  for (int j = 0; j < Size.x; j++) {
    map[j][0].allowBounce();
    map[j][Size.y - 1].allowBounce();
  }
  map[Size.x / 2][Size.y / 2].allowBounce();
  BallPosition = Size / 2;
  logBallPosition();
  //Test();
}
