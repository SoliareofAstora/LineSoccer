#pragma once


class InputController
{
	InputController();
public:
	void update();
	static InputController &instance() { static InputController inputController; return inputController; };
	void initialise(){}
	
	~InputController();
};

