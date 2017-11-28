#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class Visualization
{

public:

	void Start();
	void update(sf::RenderWindow *window);
	Visualization();
	~Visualization();
};

