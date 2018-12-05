#pragma once

class Player
{
public:
	Player();
	~Player();
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getWidth() { return this->w; }
	int getHeight() { return this->h; }
	void setSize(int w, int h) { this->w = w; this->h = h; }
	void setPos(int x, int y) { this->x = x; this->y = y; }

private:
	int x, y, w, h;
};

