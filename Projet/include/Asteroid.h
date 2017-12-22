#pragma once
#include "GraphicPrimitives.h"

class Asteroid {
protected:
	float pos_x;
	float pos_y;
	int speed;
	int life;
	float r;
	float g;
	float b;

public:
	Asteroid(float argX, float argY, int argSpeed, int argLife, float argR, float argG, float argB):
		pos_x(argX), pos_y(argY), speed(argSpeed), life(argLife),
		r(argR), g(argG), b(argB)
		{}
	void move();
	void loseLife(int l);
	float getPosX();
	float getPosY();
	float getPasAsteroid();
	bool checkAlive();
	void draw_asteroid();
	~Asteroid();

};