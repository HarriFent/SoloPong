#pragma once
class Ball
{
public:
	Ball();
	~Ball();
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getRadius() { return this->r; }
	void setSize(int r) { this->r = r; }
	void setPos(int x, int y) { this->x = x; this->y = y; }

	struct Direction {
		bool right, down;
		void setDir(bool right, bool down) 
		{
			this->right = right; this->down = down; 
		}
	};

	Direction dir;
private:
	int x, y, r;
};

