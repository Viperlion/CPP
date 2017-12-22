#include "Asteroid.h"

Asteroid::~Asteroid() {
	delete this;
}

void Asteroid::move() {
	pos_x -= speed * 0.001f;
}

void Asteroid::loseLife(int l) {
	life -= l;
}

float Asteroid::getPosX() {
	return pos_x;
}

float Asteroid::getPosY() {
	return pos_y;
}

float Asteroid::getPasAsteroid()
{
	return speed * 0.001f;
}

bool Asteroid::checkAlive() {
	return (life > 0);
}

void Asteroid::draw_asteroid() {
	GraphicPrimitives::drawFillRect2D(pos_x, pos_y + 0.05f, 0.1f, 0.1f, r, g, b);
	GraphicPrimitives::drawOutlinedRect2D(pos_x, pos_y + 0.05f, 0.1f, 0.1f, 0.0f, 0.0f, 0.0f);
}
