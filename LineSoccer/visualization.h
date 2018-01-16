#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "FieldVisualization.h"

class Visualization
{
	sf::Clock clock;
	const float FRAMES_PER_SECOND = 30;
	float FrameRate = 1000.f / FRAMES_PER_SECOND;
	float NextFrameTime = 0;
	Visualization() : window(nullptr), field(nullptr)
	{
	}

	sf::RenderWindow* window;
	
public:
	static Visualization &instance() { static Visualization visualization; return visualization; }
	FieldVisualization* field;

	void initialise();
	void draw();
	void resetField();
	sf::RenderWindow* getWindow() const { return window; }
	
	~Visualization();

};

