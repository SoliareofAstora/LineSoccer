#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "FieldVisualization.h"

class Visualization
{
	Visualization() : window(nullptr), field(nullptr)
	{
	}

	sf::RenderWindow* window;
	FieldVisualization* field;

public:
	static Visualization &instance() { static Visualization visualization; return visualization; }
	void update();
	void initialise();
	sf::RenderWindow* getWindow() const { return window; }
	
	~Visualization();

};

