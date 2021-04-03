//
// Created by soliareofastora on 20.03.2021.
//

#ifndef LINESOCCER_FIELD_FIELD_LOGIC_HPP_
#define LINESOCCER_FIELD_FIELD_LOGIC_HPP_

#include <tuple>

#include "utils/bit_set.hpp"

class FieldLogic {
  BitSet* _links;  // false-open true-closed
  int _x_dim, _y_dim;
  int _ball_x, _ball_y;

 public:
  FieldLogic(int x_dim, int y_dim);
  ~FieldLogic();
  void reset();

 public:
  std::pair<int, int> _next_xy(int x, int y, unsigned char direction);
  bool _is_link_open(int x, int y, unsigned char direction);
  void _set_link(int x, int y, unsigned char direction, bool value);
  void _close_link(int x, int y, unsigned char direction);
  void _close_link(unsigned char direction);
  unsigned char _get_open_links_directions(int x, int y, unsigned char* output);
  unsigned char _get_open_links_count(int x, int y);

 public:
  bool is_link_open(unsigned char direction);
  unsigned char get_open_links_directions(unsigned char* output);
  unsigned char get_open_links_count();
  bool move(unsigned char direction);
  void print_links();
};

#endif  // LINESOCCER_FIELD_FIELD_LOGIC_HPP_
