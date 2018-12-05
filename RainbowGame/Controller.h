#pragma once
#include "EasyGraphics.h"
#include "Model.h"

class View;

class Controller
{
public:
	Controller();
	~Controller();
	int getX() { return this->xMouse; }
	int getY() { return this->yMouse; }
	void SetMousePos(int x, int y) { this->xMouse = x, this->yMouse = y; }

	void PlayerControls(Player& p);
	void BallControls(Ball& b, Model& m, View * v);
private:
	int xMouse, yMouse;
	int playerSpeed;
};

