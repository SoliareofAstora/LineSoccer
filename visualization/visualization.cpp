#include "visualization.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include "input_handler/UI.h"

void Visualization::draw() {
  //TODO przywr�ci�
  //if (clock.getElapsedTime().asMilliseconds() > NextFrameTime)
  {
    NextFrameTime = clock.getElapsedTime().asMilliseconds() + FrameRate;
    window->clear();
    field->display(window);
    UI::instance().display(window);

    window->display();
  }
}

void Visualization::resetField() {
  field->reset();
}

void Visualization::initialise() {
  window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Line Soccer");
  field = new FieldVisualization(
      sf::Vector2f(0, 0), //offset
      sf::Vector2i(999, 999));//size
  draw();
}

Visualization::~Visualization() {
  window->close();
  delete window;
}
