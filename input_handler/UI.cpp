#include "UI.h"
#include "input_handler/InputController.h"

UI::UI() {
}

void UI::initialise() {
  InputController::instance().initialise();
}

void UI::display(sf::RenderWindow* window) {
  //arrows.display(window);
}

UI::~UI() {
}
