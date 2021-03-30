//
// Created by soliareofastora on 30.03.2021.
//

#include "field_logic.hpp"

#include <bitset>
#include <cstring>
#include <iostream>
#include <stdexcept>

FieldLogic::FieldLogic(unsigned short x_dim, unsigned short y_dim) {
  x_dim += x_dim % 2;
  if (x_dim < 10)
    x_dim = 10;
  y_dim += 1 - y_dim % 2;
  if (y_dim < 7)
    y_dim = 7;

  _x_dim = x_dim;
  _y_dim = y_dim;
  _links = new BitSet(x_dim * y_dim * 4);
  _ball_x = _x_dim / 2;
  _ball_y = _y_dim / 2;
  reset_field();
}

FieldLogic::~FieldLogic() {
  delete _links;
}

BitSet* FieldLogic::get_links() const {
  return _links;
}

void FieldLogic::reset_field() {
  // clear field
  std::memset(_links->data, 0x00, _x_dim * _y_dim / 2);

  // set rows
  std::memset(_links->data, 0xFF, _x_dim / 2);
  std::memset(&_links->data[_x_dim / 2], 0x77, _x_dim / 2);
  std::memset(&_links->data[_x_dim / 2 * (_y_dim - 2)], 0xCC, _x_dim / 2);
  std::memset(&_links->data[_x_dim / 2 * (_y_dim - 1)], 0xFF, _x_dim / 2);

  // set columns
  for (int i = 2; i < _y_dim - 2; ++i)
    _links->set_char(_x_dim / 2 * i + 1, 0x01);
  for (int i = 0; i < _y_dim; ++i) {
    _links->set_char(_x_dim / 2 * i, 0xFF);
    _links->set_char(_x_dim / 2 * (i + 1) - 1, 0xFF);
  }

  // set bottom-left corner
  _links->set_char(_x_dim / 2 * (_y_dim - 2) + 1, 0xCD);

  // left gate
  _links->set_char(_x_dim / 2 * (_y_dim / 2) + 1, 0x00);
  _links->set_char(_x_dim / 2 * (_y_dim / 2), 0x1F);
  _links->set_char(_x_dim / 2 * (_y_dim / 2 + 1) + 1, 0x00);
  _links->set_char(_x_dim / 2 * (_y_dim / 2 + 1), 0xDF);
  _links->set_char(_x_dim / 2 * (_y_dim / 2 - 1), 0xEF);

  // right gate
  _links->set_char(_x_dim / 2 * (_y_dim / 2) - 1, 0xF7);
  _links->set_char(_x_dim / 2 * (_y_dim / 2 + 1) - 1, 0xF0);
  _links->set_char(_x_dim / 2 * (_y_dim / 2 + 2) - 1, 0xFB);

  // set ball position
  _ball_x = _x_dim / 2;
  _ball_y = _y_dim / 2;
}

bool FieldLogic::is_link_open(unsigned short x, unsigned short y, unsigned char direction) {
  if (direction < 4) {
//    if (x < 0 or y < 0 or x >= _x_dim or y >= _y_dim)
//      return false;
    return !_links->get_bit((x + y * _x_dim) * 4 + direction);
  }
  if (direction == 4)
    return is_link_open(x, y + 1, 0);
  if (direction == 5)
    return is_link_open(x - 1, y + 1, 1);
  if (direction == 6)
    return is_link_open(x - 1, y, 2);
  if (direction == 7)
    return is_link_open(x - 1, y - 1, 3);
  throw std::runtime_error("direction must be in range of [0,7]");
}

bool FieldLogic::is_link_open(unsigned char direction) {
  return is_link_open(_ball_x, _ball_y, direction);
}

unsigned char FieldLogic::get_open_links_directions(unsigned short x, unsigned short y, unsigned char* output) {
  unsigned char length = 0;
  for (unsigned char i = 0; i < 8; ++i) {
    if (is_link_open(x, y, i)) {
      output[length++] = i;
    }
  }
  return length;
}

unsigned char FieldLogic::get_open_links_directions(unsigned char* output) {
  return get_open_links_directions(_ball_x, _ball_y, output);
}

unsigned char FieldLogic::get_open_links_count(unsigned short x, unsigned short y) {
  unsigned char length = 0;
  for (unsigned char i = 0; i < 8; ++i) {
    if (is_link_open(x, y, i)) {
      ++length;
    }
  }
  return length;
}

unsigned char FieldLogic::get_open_links_count() {
  return get_open_links_count(_ball_x, _ball_y);
}

void FieldLogic::set_link(unsigned short x, unsigned short y, unsigned char direction, bool value) {
  if (direction < 4) {
    if (x < 0 or y < 0 or x >= _x_dim or y >= _y_dim)
      throw std::runtime_error("Trying to set link outsize of the field");
    return _links->set_bit((x + y * _x_dim) * 4 + direction, value);
  }
  if (direction == 4)
    return set_link(x, y + 1, 0, value);
  if (direction == 5)
    return set_link(x - 1, y + 1, 1, value);
  if (direction == 6)
    return set_link(x - 1, y, 2, value);
  if (direction == 7)
    return set_link(x - 1, y - 1, 3, value);
  throw std::runtime_error("direction must be in range of [0,7]");
}

void FieldLogic::close_link(unsigned short x, unsigned short y, unsigned char direction) {
  set_link(x, y, direction, true);
}

void FieldLogic::close_link(unsigned char direction) {
  set_link(_ball_x, _ball_y, direction, true);
}

void FieldLogic::print_links() {
  for (unsigned short j = 0; j < _y_dim; ++j) {
    for (unsigned short i = 0; i < _x_dim; ++i) {
      auto tmp = std::bitset<4>();
      for (unsigned char k = 0; k < 4; k++)
        tmp[k] = _links->get_bit((i + j * _x_dim) * 4 + k);
      printf("%*ld", 3, tmp.to_ulong());
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}