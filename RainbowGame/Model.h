#pragma once
#include "Player.h"
#include "Ball.h"
#include <vector>

class Model
{
public:
	Model();
	~Model();

	void incScore() { this->score++; }
	void setScore(int score) { this->score = score; }
	int getScore() { return this->score; }

	Player player;
	std::vector<Ball> balls;
private:
	int score;
};

