//
// Created by soliareofastora on 30.03.2021.
//

#include "field_logic.h"

#include <bitset>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <tuple>

FieldLogic::FieldLogic(int x_dim, int y_dim) {
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
}

FieldLogic::~FieldLogic() {
  delete _links;
}

void FieldLogic::reset() {
  // clear field
  std::memset(_links->data, 0x00, _x_dim * _y_dim / 2);

  // set rows
  std::memset(_links->data, 0x77, _x_dim / 2);
  std::memset(&_links->data[_x_dim / 2 * (_y_dim - 1)], 0xCC, _x_dim / 2);

  // set columns
  for (unsigned int i = 1; i < _y_dim - 1; ++i) {
    _links->set_char(_x_dim / 2 * i, 0x1F);
    _links->set_char(_x_dim / 2 * (i + 1) - 1, 0xF0);
  }

  // set corners
  _links->set_char(0, 0x7F);
  _links->set_char(_x_dim / 2 - 1, 0xF7);
  _links->set_char(_x_dim / 2 * (_y_dim - 1), 0xDF);
  _links->set_char(_x_dim / 2 * (_y_dim)-1, 0xFC);

  // left gate
  _links->set_char(_x_dim / 2 * (_y_dim / 2 - 1), 0x17);
  _links->set_char(_x_dim / 2 * (_y_dim / 2), 0x01);
  _links->set_char(_x_dim / 2 * (_y_dim / 2 + 1), 0x0D);

  // right gate
  _links->set_char(_x_dim / 2 * (_y_dim / 2) - 1, 0x70);
  _links->set_char(_x_dim / 2 * (_y_dim / 2 + 1) - 1, 0x00);
  _links->set_char(_x_dim / 2 * (_y_dim / 2 + 2) - 1, 0x80);

  // set ball position
  _ball_x = _x_dim / 2;
  _ball_y = _y_dim / 2;
}

std::pair<int, int> FieldLogic::_linked_xy(int x, int y, unsigned char direction) {
  if (direction == 0)
    return {x, y - 1};
  if (direction == 1)
    return {x + 1, y - 1};
  if (direction == 2)
    return {x + 1, y};
  if (direction == 3)
    return {x + 1, y + 1};
  if (direction == 4)
    return {x, y + 1};
  if (direction == 5)
    return {x - 1, y + 1};
  if (direction == 6)
    return {x - 1, y};
  if (direction == 7)
    return {x - 1, y - 1};
  throw std::runtime_error("Direction must be in range 0..7");
}

bool FieldLogic::_is_link_open(int x, int y, unsigned char direction) {
  if (direction < 4) {
    if (x < 0 or y < 0 or x >= _x_dim or y >= _y_dim)
      return false;
    return !_links->get_bit((x + y * _x_dim) * 4 + direction);
  } else {
    int new_x, new_y;
    std::tie(new_x, new_y) = _linked_xy(x, y, direction);
    return _is_link_open(new_x, new_y, direction - 4);
  }
}

void FieldLogic::_set_link(int x, int y, unsigned char direction, bool value) {
  if (direction < 4) {
    if (x < 0 or y < 0 or x >= _x_dim or y >= _y_dim)
      throw std::runtime_error("Trying to set link outsize of the field");
    return _links->set_bit((x + y * _x_dim) * 4 + direction, value);
  } else {
    int new_x, new_y;
    std::tie(new_x, new_y) = _linked_xy(x, y, direction);
    _set_link(new_x, new_y, direction - 4, value);
  }
  if(_visualizer){

  }
}

void FieldLogic::_close_link(int x, int y, unsigned char direction) {
  _set_link(x, y, direction, true);
}

void FieldLogic::_close_link(unsigned char direction) {
  _set_link(_ball_x, _ball_y, direction, true);
}

unsigned char FieldLogic::_get_open_links_directions(int x, int y, unsigned char* output) {
  unsigned char length = 0;
  for (unsigned char i = 0; i < 8; ++i) {
    if (_is_link_open(x, y, i)) {
      output[length++] = i;
    }
  }
  return length;
}

unsigned char FieldLogic::_get_open_links_count(int x, int y) {
  unsigned char length = 0;
  for (unsigned char i = 0; i < 8; ++i) {
    if (_is_link_open(x, y, i)) {
      ++length;
    }
  }
  return length;
}

bool FieldLogic::is_link_open(unsigned char direction) {
  return _is_link_open(_ball_x, _ball_y, direction);
}

unsigned char FieldLogic::get_open_links_directions(unsigned char* output) {
  return _get_open_links_directions(_ball_x, _ball_y, output);
}

unsigned char FieldLogic::get_open_links_count() {
  return _get_open_links_count(_ball_x, _ball_y);
}

void FieldLogic::print_links() {
  for (unsigned int j = 0; j < _y_dim; ++j) {
    for (unsigned int i = 0; i < _x_dim; ++i) {
      auto tmp = std::bitset<4>();
      for (unsigned char k = 0; k < 4; k++)
        tmp[k] = _links->get_bit((i + j * _x_dim) * 4 + k);
      printf("%*ld", 3, tmp.to_ulong());
    }
    std::cout << '\n';
  }
  std::cout << "x:" << _ball_x << " y: " << _ball_y << '\n';
}

bool FieldLogic::move(unsigned char direction) {
  if (!is_link_open(direction))
    throw std::runtime_error("Trying to move over closed link");

  int new_x, new_y;
  std::tie(new_x, new_y) = _linked_xy(_ball_x, _ball_y, direction);
  auto open_links = _get_open_links_count(new_x, new_y);

  bool move_finished = false;
  if (open_links == 0 or open_links == 8 or new_x == 0 or new_x == _x_dim)
    move_finished = true;

  _close_link(direction);
  _ball_x = new_x;
  _ball_y = new_y;

  return move_finished;
}

void FieldLogic::attach_visualizer(FieldVisualizer* visualizer) {
  _visualizer = visualizer;
}
