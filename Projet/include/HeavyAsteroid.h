#pragma once
#include "Asteroid.h"

class HeavyAsteroid : public Asteroid {
protected:
	float pos_x;
	float pos_y;
	int speed;
	int life;
	float r;
	float g;
	float b;

public:
	HeavyAsteroid(float argX, float argY) :
		Asteroid(argX, argY, 4, 200, 0.3f, 0.1f, 0.1f)
	{}

	~HeavyAsteroid() { }
};