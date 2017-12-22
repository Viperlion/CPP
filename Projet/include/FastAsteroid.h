#pragma once
#include "Asteroid.h"

class FastAsteroid : public Asteroid {
protected:
	float pos_x;
	float pos_y;
	int speed;
	int life;
	float r;
	float g;
	float b;

public:
	FastAsteroid(float argX, float argY) :
		Asteroid(argX, argY, 9, 14, 0.1f, 0.1f, 0.3f)
	{}

	~FastAsteroid() { }
};