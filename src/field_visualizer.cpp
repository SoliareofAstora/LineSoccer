//
// Created by soliareofastora on 07.04.2021.
//

#include "field_visualizer.h"

//sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Test");
//sf::Image        image(800, 600, sf::Color(0, 0, 0));
//sf::Sprite       sprite;
//sf::Uint8        *pixels  = new sf::Uint8[800 * 600 * 4];
//// ...
//while(window.IsOpened())
//{
//// ...
//for(int x = 0; x < 800; x++)
//{
//for(int y = 0; y < 600; y++)
//{
//pixels[y * x]     = 255; // R?
//pixels[y * x + 1] = 255; // G?
//pixels[y * x + 2] = 255; // B?
//pixels[y * x + 3] = 255; // A?
//}
//}
//// ...
//image.LoadFromPixels(800, 600, pixels);
//sprite.SetImage(image);
//window.Draw(sprite);
//window.Display();
//}
//// ...
//delete [] pixels;
//// ...
//
//FieldVisualization::FieldVisualization(sf::Vector2f offset, sf::Vector2i sprSizePx) {
//  fieldSprite.setPosition(offset);
//  image.create(sprSizePx.x, sprSizePx.y, sf::Color::Black);
//  texture.create(sprSizePx.x, sprSizePx.y);
//  updateLogicSize();
//}
//
//void FieldVisualization::reset() {
//  auto spritePxSize = image.getSize();
//  auto logicSize = GameLogic::instance().fieldSize();
//  image.create(spritePxSize.x, spritePxSize.y, sf::Color::Black);
//  createNodeDots(logicSize);
//  createFieldBorder(logicSize);
//}
//
//void FieldVisualization::display(sf::RenderWindow* window) {
//  texture.update(image);
//  fieldSprite.setTexture(texture);
//  window->draw(fieldSprite);
//}
//
//void FieldVisualization::updateLogicSize() {
//  auto spritePxSize = image.getSize();
//  auto logicSize = GameLogic::instance().fieldSize();
//
//  spritePxSize.x /= logicSize->x;
//  spritePxSize.y /= logicSize->y;
//  spritePxSize.x -= logicSize->x % 2;
//  spritePxSize.y -= logicSize->y % 2;
//  step = std::min(spritePxSize.x, spritePxSize.y);
//  reset();
//}
//
//void FieldVisualization::createNodeDots(sf::Vector2i* logicSize) {
//  for (int i = 1; i < logicSize->x; i++) {
//    for (int j = 0; j < logicSize->y; j++) {
//      drawNode(i, j);
//    }
//  }
//  image.setPixel(logicSize->x / 2 * step, logicSize->y / 2 * step, sf::Color::Red);
//}
//
//void FieldVisualization::createFieldBorder(sf::Vector2i* logicSize) {
//  stack<Move> moves;
//  for (int i = 0; i < logicSize->x; i++) {
//    if (i == 0 || i == logicSize->x - 1) {
//      moves.push(Move(i, (logicSize->y / 2) - 1, 2));
//      moves.push(Move(i, (logicSize->y / 2) - 1, 2));
//      moves.push(Move(i, (logicSize->y / 2) + 1, 2));
//    } else {
//      moves.push(Move(i, 0, 2));
//      moves.push(Move(i, logicSize->y - 1, 2));
//    }
//  }
//
//  for (int i = 1; i < logicSize->y; i++) {
//    if (i > (logicSize->y / 2) - 1 && i < (logicSize->y / 2) + 2) {
//      drawNode(0, i);
//      drawNode(logicSize->x, i);
//      moves.push(Move(0, i, 0));
//      moves.push(Move(logicSize->x, i, 0));
//    } else {
//      moves.push(Move(1, i, 0));
//      moves.push(Move(logicSize->x - 1, i, 0));
//    }
//  }
//
//  drawNode(0, (logicSize->y / 2) - 1);
//  drawNode(logicSize->x, (logicSize->y / 2) - 1);
//
//  while (!moves.empty()) drawLine(moves.pop(), sf::Color::White);
//}
//
//void FieldVisualization::drawNode(int addrx, int addry) {
//  image.setPixel(addrx * step, addry * step, sf::Color::White);
//}
//
//void FieldVisualization::drawLine(Move move, sf::Color color) {
//  int x = move.addrx * step;
//  int y = move.addry * step;
//  int dx = 0;
//  int dy = 0;
//
//  if (move.direction > 0) {
//    dx = 1;
//  }
//
//  if (move.direction < 2) {
//    dy = -1;
//  }
//  if (move.direction == 3) {
//    dy = 1;
//  }
//
//  for (uint8_t i = 1; i < step; i++) {
//    x += dx;
//    y += dy;
//    image.setPixel(x, y, color);
//  }
//}
//
//void FieldVisualization::removeLine(Move move) {
//  drawLine(move, sf::Color::Black);
//}
//
//FieldVisualization::~FieldVisualization() {
//}
FieldVisualizer::FieldVisualizer() {

}
