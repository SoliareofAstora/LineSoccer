#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "FieldVisualization.h"

class Visualization {
  sf::Clock clock;
  const int FRAMES_PER_SECOND = 30;
  sf::Int32 FrameRate = 1000 / FRAMES_PER_SECOND;
  sf::Int32 NextFrameTime = 0;
  Visualization():window(nullptr), field(nullptr) {
  }

  sf::RenderWindow* window;

 public:
  static Visualization &instance() {
    static Visualization visualization;
    return visualization;
  }
  FieldVisualization* field;

  void initialise();
  void draw();
  void resetField();
  sf::RenderWindow* getWindow() const { return window; }

  ~Visualization();

};

