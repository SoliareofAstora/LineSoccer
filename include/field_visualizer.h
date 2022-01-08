//
// Created by soliareofastora on 07.04.2021.
//

#ifndef LINESOCCER_INCLUDE_FIELD_VISUALIZER_H_
#define LINESOCCER_INCLUDE_FIELD_VISUALIZER_H_

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Sprite.hpp>

class FieldVisualizer {
  sf::Image _image;
  sf::Sprite _field_sprite;

  int _step;
  sf::Color _current_color;
  sf::Color _background_color;

  void _draw_link(int x, int y, unsigned char direction, sf::Color color);
 public:
  FieldVisualizer();
  void draw_link(int x, int y, unsigned char direction);
  void erase_link(int x, int y, unsigned char direction);

  //  void createNodeDots(sf::Vector2i* logicSize);
  //  void createFieldBorder(sf::Vector2i* logicSize);
  //  void drawNode(int addrx, int addry);
  // public:
  //  FieldVisualization(sf::Vector2f position, sf::Vector2i pixelSize);
  //  void reset();
  //  void display(sf::RenderWindow* window);
  //  void updateLogicSize();
  //  void drawLine(Move move, sf::Color color);
  //  void removeLine(Move move);
  //  ~FieldVisualization();
};

#endif  // LINESOCCER_INCLUDE_FIELD_VISUALIZER_H_
