#pragma once
#include "EasyGraphics.h"
#include "Model.h"
#include "Controller.h"

class View : public EasyGraphics
{
public:
	View(HINSTANCE hInstance);
	~View();
	virtual void onDraw();
	virtual void onMouseMove(UINT nFlags, int x, int y);
	virtual void onTimer(UINT nIDEvent);

	void drawDigit(int digit, int x, int y);
private:
	Model model;
	Controller controller;

};

