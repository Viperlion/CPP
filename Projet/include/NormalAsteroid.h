#pragma once
#include "Asteroid.h"

class NormalAsteroid : public Asteroid {
protected:
	float pos_x;
	float pos_y;
	int speed;
	int life;
	float r;
	float g;
	float b;

public :
	NormalAsteroid(float argX, float argY) :
		Asteroid(argX, argY, 4, 12, 0.1f, 0.3f, 0.1f)
	{}

	~NormalAsteroid() { }
};