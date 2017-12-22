#pragma once
#include "GraphicPrimitives.h"
#include "Missile.h"

class Turret {

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
	// upgrade's level
	int lvl;
	// turret's type
	char* type;
	// turret's values
	int value;
	int lvlUpPrice;
	// missile
	bool shoot;
	int cpt;
	Missile missile;

public:
	Turret(float pos_x, float pos_y, float r, float g, float b) :
		pos_x(pos_x), pos_y(pos_y), power(7), speed(7),
		r(r), g(g), b(b),
		lvl(1), type(new char[10]{ 'N','o','r','m','a','l','e',' ',':','\0' }),
		value(250), lvlUpPrice(50),
		shoot(false), cpt(0), missile(*new Missile(pos_x, pos_y, power, speed, 0.1f, 0.9f, 0.1f))
	{}

	char* getType();
	void setType(char* t);
	int getLvl();
	void setLvl(int l);
	int getSpeed();
	int getPower();
	void setLourde();
	void setRapide();
	void drawTurret();
	void lvlUpPower();
	void lvlUpSpeed();
	bool haveShoot();
	void setShoot(bool s);
	void init();
	int getValue();
	int getLvlUpPrice();
	float getPosX();
	float getPosY();
	void missile_init();
	void drawMissile();
	void moveMissile();
	Missile getMissile();
	float getMissileX();
	float getMissileY();
	float getMissilePas();
	int getMissilePower();
	void setCooldown();
	bool isCooldown();
};