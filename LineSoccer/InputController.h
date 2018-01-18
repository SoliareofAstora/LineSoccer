#pragma once


class InputController
{
	InputController();
	bool awaitingSpacebar = true;
public:
	void update();
	static InputController &instance() { static InputController inputController; return inputController; };
	void initialise(){}
	
	~InputController();
};

