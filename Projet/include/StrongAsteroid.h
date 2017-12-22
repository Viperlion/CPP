#pragma once
#include "Asteroid.h"

class StrongAsteroid : public Asteroid {
protected:
	float pos_x;
	float pos_y;
	int speed;
	int life;
	float r;
	float g;
	float b;

public:
	StrongAsteroid(float argX, float argY) :
		Asteroid(argX, argY, 5, 15, 0.3f, 0.3f, 0.1f)
	{}

	~StrongAsteroid() { }
};