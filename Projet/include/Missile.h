#pragma once
#include "GraphicPrimitives.h"

class Missile {
protected:
	//pos
	float pos_x;
	float pos_y;
	// projectile
	int power;
	int speed;
	// color
	float r;
	float g;
	float b;

public:
	Missile(float argX, float argY, int argPower, int argSpeed,
		float argR, float argG, float argB) :
		pos_x(argX), pos_y(argY),
		power(argPower), speed(argSpeed),
		r(argR), g(argG), b(argB)
	{}

	void drawMissile();
	void setNewPos();
	void re_init(float x, int p, int s, float new_r, float new_g, float new_b);
	float getPosX();
	float getPosY();
	float getPas();
	int getPower();
};