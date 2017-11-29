#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

class Visualization
{
	Visualization() {}
	sf::RenderWindow* window;
public:
	static Visualization &instance() { static Visualization visualization; return visualization; }
	void update();
	void initialise();
	sf::RenderWindow* getWindow() const { return window; }
	
	~Visualization();

};

