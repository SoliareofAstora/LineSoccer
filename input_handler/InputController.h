#pragma once
#include <SFML/Graphics/Color.hpp>

class InputController {
  InputController();
  bool awaitingSpacebar = false;

  sf::Color tempcolor = sf::Color::White;
 public:
  void update();
  static InputController &instance() {
    static InputController inputController;
    return inputController;
  };
  void initialise() {}

  ~InputController();
};

