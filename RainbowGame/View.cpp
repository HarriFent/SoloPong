#include "View.h"
#include "EasyGraphics.h"

View::View(HINSTANCE hInstance)
{
	setImmediateDrawMode(false);
	create(hInstance, 1024, 768, 40, false);
	setTimer(1,1);
	waitForClose();
}

View::~View()
{
}

void View::onDraw()
{
	clrscr(clBlack);

	//Draw Score
	drawDigit(model.getScore() % 10, 500, 200);
	drawDigit(model.getScore() / 10, 450, 200);

	//Draw balls
	for (std::vector<Ball>::iterator it = model.balls.begin(); it != model.balls.end(); ++it)
	{
		selectBackColour(clRed);
		setPenColour(clDarkRed, 3);
		Ball ball = *it;
		drawCircle(ball.getX(), ball.getY(), ball.getRadius(), true);
	}
	
	//Draw player
	selectBackColour(clGreen);
	setPenColour(clDarkGreen, 3);
	drawRectangle(model.player.getX(), model.player.getY(), model.player.getWidth(), model.player.getHeight(), true);

	EasyGraphics::onDraw();
}

void View::onMouseMove(UINT nFlags, int x, int y)
{
	controller.SetMousePos(x, y);
	EasyGraphics::onMouseMove(nFlags, x, y);
}

void View::onTimer(UINT nIDEvent)
{
	//Player controls
	controller.PlayerControls(model.player);

	//Ball control
	for (int i = 0; i < model.balls.size(); i++)
	{
		controller.BallControls(model.balls.at(i), model, this);
		if (i > model.balls.size())
			break;
	}

	onDraw();
	EasyGraphics::onTimer(nIDEvent);
}

void View::drawDigit(int digit, int x, int y)
{
	const wchar_t* loc;
	switch (digit)
	{
	case 0:
		loc = L"char0.bmp";
		break;
	case 1:
		loc = L"char1.bmp";
		break;
	case 2:
		loc = L"char2.bmp";
		break;
	case 3:
		loc = L"char3.bmp";
		break;
	case 4:
		loc = L"char4.bmp";
		break;
	case 5:
		loc = L"char5.bmp";
		break;
	case 6:
		loc = L"char6.bmp";
		break;
	case 7:
		loc = L"char7.bmp";
		break;
	case 8:
		loc = L"char8.bmp";
		break;
	case 9:
		loc = L"char9.bmp";
		break;
	default:
		loc = L"";
	}
	drawBitmap(loc, x, y, 64, 64);
}
