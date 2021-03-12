#pragma once
#include <bitset>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Move {

 public:
  int addrx;
  int addry;
  uint8_t direction;
  bool changed = false;

  Move():addrx(0), addry(0), direction(0) {}

  Move(int addrx, int addry, uint8_t direction):addrx(addrx), addry(addry), direction(direction) {
    checkDirection();
  }
  Move(sf::Vector2i addr, uint8_t direction):addrx(addr.x), addry(addr.y), direction(direction) {
    checkDirection();
  }

  sf::Vector2i GetDestination() {
    return calculateVector(true);
  }

  sf::Vector2i GetSource() {
    return calculateVector(true);
  }

  sf::Vector2i calculateVector(bool option) {
    int x = addrx;
    int y = addry;
    if (changed != option) {
      if (direction > 0) {
        x++;
      }
      if (direction < 2) {
        y--;
      }
      if (direction == 3) {
        y++;
      }
    }
    return sf::Vector2i(x, y);
  }

  void checkDirection() {
    if (direction > 7) {
      direction -= 8;
    }
    if (direction > 3) {
      changed = true;
      if (direction > 4) {
        addrx--;
      }
      if (direction == 7) {
        addry--;
      }
      if (direction < 6) {
        addry++;
      }
      direction -= 4;
    }
  }
};
