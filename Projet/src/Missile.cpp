#include "Missile.h"

void Missile::drawMissile() {
	GraphicPrimitives::drawFillRect2D(pos_x, pos_y - 0.005f, 0.04f, 0.01f, r, g, b);
}

void Missile::setNewPos() {
	pos_x += speed * 0.001f;
}

void Missile::re_init(float x, int p, int s, float new_r, float new_g, float new_b) {
	pos_x = x;
	power = p;
	speed = s;
	r = new_r;
	g = new_g;
	b = new_b;
}

float Missile::getPosX() {
	return pos_x;
}

float Missile::getPosY() {
	return pos_y;
}

int Missile::getPower() {
	return power;
}

float Missile::getPas() {
	return speed * 0.001f;
}