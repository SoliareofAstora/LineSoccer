//
// Created by soliareofastora on 20.03.2021.
//

#ifndef LINESOCCER_FIELD_FIELD_LOGIC_HPP_
#define LINESOCCER_FIELD_FIELD_LOGIC_HPP_

#include "utils/bit_set.hpp"
#include <cstring>

class FieldLogic {
  int _x_dim, _y_dim;
  int _ball_x, _ball_y;
public:
  // TODO links should be private (I guess)
  BitSet *_links; // false-open true-closed
  FieldLogic(int x_dim, int y_dim) {
    x_dim += x_dim % 2;
    if (x_dim < 10) {
      x_dim = 10;
    }
    y_dim += 1 - y_dim % 2;
    if (y_dim < 7) {
      y_dim = 7;
    }

    _x_dim = x_dim;
    _y_dim = y_dim;
    _links = new BitSet(x_dim * y_dim * 4);
    reset_field();
  }

  ~FieldLogic() { delete _links; }

  void reset_field() {
    // clear field
    std::memset(_links->data, 0x00, _x_dim * _y_dim / 2);

    // set rows
    std::memset(_links->data, 0xFF, _x_dim / 2);
    std::memset(&_links->data[_x_dim / 2], 0x77, _x_dim / 2);
    std::memset(&_links->data[_x_dim / 2 * (_y_dim - 2)], 0xCC, _x_dim / 2);
    std::memset(&_links->data[_x_dim / 2 * (_y_dim - 1)], 0xFF, _x_dim / 2);

    // set columns
    for (int i = 0; i < _y_dim; ++i) {
      _links->set_char(_x_dim / 2 * i, 0xFF);
      _links->set_char(_x_dim / 2 * (i + 1) - 1, 0xFF);
    }
    for (int i = 2; i < _y_dim - 2; ++i)
      _links->set_char(_x_dim / 2 * i + 1, 0x01);

    // fix bottom-left corner
    _links->set_char(_x_dim / 2 * (_y_dim - 1) + 1, 0xCD);

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

  bool check_link(int x, int y, int direction) {
    if (direction < 4)
      return _links->get_bit((x * _x_dim + y) * 4 + direction);
    if (direction == 4)
      return check_link(x, y + 1, 0);
    if (direction == 5)
      return check_link(x - 1, y + 1, 1);
    if (direction == 6)
      return check_link(x - 1, y, 2);
    if (direction == 7)
      return check_link(x - 1, y - 1, 3);
  };

  bool check_link(int direction) {
    return check_link(_ball_x, _ball_y, direction);
  }

  void set_link(int x, int y, int direction, bool value) {
    if (direction < 4)
      _links->set_bit((x * _x_dim + y) * 4 + direction, value);
    if (direction == 4)
      return set_link(x, y + 1, 0, value);
    if (direction == 5)
      return set_link(x - 1, y + 1, 1, value);
    if (direction == 6)
      return set_link(x - 1, y, 2, value);
    if (direction == 7)
      return set_link(x - 1, y - 1, 3, value);
  }

  void close_link(int x, int y, int direction) {
    set_link(x, y, direction, true);
  }
};
#endif // LINESOCCER_FIELD_FIELD_LOGIC_HPP_
