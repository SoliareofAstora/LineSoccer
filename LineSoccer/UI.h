#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Arrows.h"

class UI
{
	UI();
	Arrows arrows;
public:
	static UI &instance() { static UI ui; return ui; }
	void initialise();
	void display(sf::RenderWindow* window);
	~UI();
};

