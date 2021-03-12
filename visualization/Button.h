#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class Button {
 public:
  sf::Sprite sprite;
  sf::Texture texture;
  Button() {};
  Button(sf::Vector2f offset, sf::Vector2i sprSizePx) {
    sprite.setPosition(offset);
    sf::Image image;
    image.create(sprSizePx.x, sprSizePx.y, sf::Color::White);
    texture.create(sprSizePx.x, sprSizePx.y);
    texture.update(image);
    sprite.setTexture(texture);
  }
  Button(sf::Vector2f offset, sf::Vector2i sprSizePx, sf::String ImagePath) {
    sprite.setPosition(offset);
    texture.loadFromFile(ImagePath);
    sprite.setTexture(texture);
  }

  void display(sf::RenderWindow* window) {
    sprite.setTexture(texture);
    window->draw(sprite);
  }
};
