#include "Model.h"

Model::Model()
{
	player.setSize(200, 40);
	player.setPos(10,650);
	Ball ball;
	ball.setSize(15);
	ball.dir.setDir(true,true);
	ball.setPos(50, 50);
	balls.push_back(ball);
}


Model::~Model()
{
}
