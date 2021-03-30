//
// Created by soliareofastora on 20.03.2021.
//

#ifndef LINESOCCER_FIELD_FIELD_LOGIC_HPP_
#define LINESOCCER_FIELD_FIELD_LOGIC_HPP_

#include "utils/bit_set.hpp"

class FieldLogic {
  BitSet* _links;  // false-open true-closed
  unsigned short _x_dim, _y_dim;
  unsigned short _ball_x, _ball_y;

 public:
  FieldLogic(unsigned short x_dim, unsigned short y_dim);
  ~FieldLogic();
  BitSet* get_links() const;
  void reset_field();

  bool is_link_open(unsigned short x, unsigned short y, unsigned char direction);
  bool is_link_open(unsigned char direction);

  unsigned char get_open_links_directions(unsigned short x, unsigned short y, unsigned char* output);
  unsigned char get_open_links_directions(unsigned char* output);
  unsigned char get_open_links_count(unsigned short x, unsigned short y);
  unsigned char get_open_links_count();

  void set_link(unsigned short x, unsigned short y, unsigned char direction, bool value);
  void close_link(unsigned short x, unsigned short y, unsigned char direction);
  void close_link(unsigned char direction);

  void print_links();
};

#endif  // LINESOCCER_FIELD_FIELD_LOGIC_HPP_
