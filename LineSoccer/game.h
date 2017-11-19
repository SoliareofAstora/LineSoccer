#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
	Game();


public:
	sf::RenderWindow* window;
	static Game &instance(){ static Game game; return game; };

	~Game();
	void Start();
	void Play() const;
};

