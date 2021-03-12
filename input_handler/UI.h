#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class UI {
  UI();
 public:
  static UI &instance() {
    static UI ui;
    return ui;
  }
  void initialise();
  void display(sf::RenderWindow* window);
  ~UI();
};

