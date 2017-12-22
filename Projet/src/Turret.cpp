#include "Turret.h"

char* Turret::getType() {
	return type;
}

void Turret::setType(char* t) {
	type = t;
}

int Turret::getLvl() {
	return lvl;
}

void Turret::setLvl(int l) {
	lvl = l;
}

int Turret::getSpeed() {
	return speed;
}

int Turret::getPower(){
	return power;
}

void Turret::setLourde() {
	power = 12;
	speed = 3;
	type = new char[9]{ 'L','o','u','r','d','e',' ',':','\0' };
}

void Turret::setRapide() {
	power = 3;
	speed = 12;
	type = new char[9]{ 'R','a','p','i','d','e',' ',':','\0' };
}

void Turret::drawTurret() {
	GraphicPrimitives::drawFillTriangle2D(pos_x, pos_y, pos_x - 0.1f, pos_y - 0.05f, pos_x - 0.1f, pos_y + 0.05f, r, g, b);
}

void Turret::init() {
	speed = 7;
	power = 7;
	lvl = 1;
	value = 250;
	lvlUpPrice = 50;
	type = new char[10]{ 'N','o','r','m','a','l','e',' ',':','\0' };
}

void Turret::lvlUpPower() {
	if (lvl < 5) {
		power = power + 1;
		value = value + lvlUpPrice / 2;
		lvlUpPrice = lvlUpPrice + 50;
		lvl++;
	}
}

void Turret::lvlUpSpeed() {
	if (lvl < 5) {
		speed = speed + 1;
		value = value + lvlUpPrice / 2;
		lvlUpPrice = lvlUpPrice + 50;
		lvl++;
	}
}

bool Turret::haveShoot() {
	return shoot;
}

void Turret::setShoot(bool s) {
	shoot = s;
}

int Turret::getValue() {
	return value;
}

int Turret::getLvlUpPrice() {
	return lvlUpPrice;
}

float Turret::getPosX() {
	return pos_x;
}

float Turret::getPosY() {
	return pos_y;
}

void Turret::missile_init() {
	float mr = 0.1f;
	float mg = 0.9f;
	float mb = 0.1f;
	if (power >= 12) {
		mr = 0.9f;
		mg = 0.1f;
	}
	else if (speed >= 12) {
		mb = 0.9f;
		mg = 0.1f;
	}
	missile.re_init(pos_x, power, speed, mr, mg, mb);
}

void Turret::drawMissile(){
	missile.drawMissile();
}

void Turret::moveMissile() {
	missile.setNewPos();
}

Missile Turret::getMissile() {
	return missile;
}

float Turret::getMissileX() {
	return missile.getPosX();
}

float Turret::getMissileY() {
	return missile.getPosY();
}

float Turret::getMissilePas()
{
	return missile.getPas();
}

int Turret::getMissilePower()
{
	return missile.getPower();
}

void Turret::setCooldown() {
	shoot = false;
	cpt = 20 - speed;	// Frequence de tir basee sur la vitesse des projectiles
}

bool Turret::isCooldown() {
	cpt -= 1;
	return (cpt > 0);
}