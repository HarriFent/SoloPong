#include "Controller.h"
#include "Model.h"
#include "View.h"

Controller::Controller()
{
	playerSpeed = 6;
}

Controller::~Controller()
{
}

void Controller::PlayerControls(Player & p)
{
	if (xMouse >= 100 && xMouse <= 920)
	{
		p.setPos(xMouse - (p.getWidth() / 2), 650);
	}
}

void Controller::BallControls(Ball & b, Model& m, View * v)
{
	if (b.dir.right)
	{
		b.setPos(b.getX() + playerSpeed, b.getY());
	}
	else
	{
		b.setPos(b.getX() - playerSpeed, b.getY());
	}

	if (b.dir.down)
	{
		b.setPos(b.getX(), b.getY() + playerSpeed);
	}
	else
	{
		b.setPos(b.getX(), b.getY() - playerSpeed);
	}

	//Collision with player
	if (b.getY() + b.getRadius() >= m.player.getY() && b.getY() + b.getRadius() <= m.player.getY() + m.player.getHeight())
	{
		if (b.getX() >= m.player.getX() && b.getX() <= m.player.getX() + m.player.getWidth())
		{
			b.dir.down = false;
		}
	}

	//collision with Wall
	int screenW, screenH;
	v->getDrawableSize(screenW, screenH);
	if (b.getX() + b.getRadius() <= 30)
	{
		b.dir.right = true;
	}
	else if (b.getX() + b.getRadius() >= screenW)
	{
		b.dir.right = false;
	}

	if (b.getY() + b.getRadius() <= 30)
	{
		b.dir.down = true;
		m.incScore();
		playerSpeed = 5 + (m.getScore() / 5);
		/*
		if (m.balls.size() < 1 + (m.getScore()/10)) {
			Ball ball;
			ball.setSize(15);
			ball.dir.setDir(true, true);
			ball.setPos(50, 250);
			m.balls.push_back(ball);
		}
		*/
	}

	if (b.getY() + b.getRadius() >= screenH)
	{
		b.dir.setDir(true, true);
		b.setPos(50, 50);
		m.setScore(0);
		v->setImmediateDrawMode(true);
		v->drawBitmap(L"gameover.bmp",335,300,330,64);
		v->setImmediateDrawMode(false);

		//reset ball vector
		m.balls.clear();
		Ball ball;
		ball.setSize(15);
		ball.dir.setDir(true, true);
		ball.setPos(50, 50);
		m.balls.push_back(ball);

		Sleep(4000);
		playerSpeed = 5;
	}
}


