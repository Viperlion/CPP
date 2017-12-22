#pragma once
#include "GraphicPrimitives.h"
#include "Menu.h"
#include "Turret.h"

class Dalle {

protected:
	float x, y;
	float height, width;
	// color
	float r;
	float g;
	float b;
	// bool;
	bool active;
	bool b_turret;
	// menus
	Menu menu;
	// turret
	Turret turret;

public:
	Dalle(float fx = 0.0f, float fy = 0.0f, float r = 0.5f, float g = 0.5f, float b = 0.5f):
		x(fx), y(fy),
		height(0.2f), width(0.2f),
		r(r), g(g), b(b),
		active(false),
		b_turret(false),
		menu(*new Menu()),
		turret(*new Turret(fx + 0.1f, fy + 0.1f, 0.8f - r, 0.8f - g, 0.8f - b))
	{
		setMenuAchat();
	}

	void draw();
	void changeColor(float r, float g, float b);
	void drawMenu();
	void setActive(bool b);
	bool isActive();
	void setTurret(bool b);
	bool haveTurret();
	Turret getTurret();
	void drawTurret();
	void setMenuAchat();
	void setMenuTurret();
	void sellTurret();
	void turretSetLourde();
	void turretSetRapide();
	void turretLvlUpPower();
	void turretLvlUpSpeed();
	float turretGetX();
	float turretGetY();
	void drawMissile();
	bool isShooting();
	void setShooting(bool b);
	void initMissile();
	void moveMissile();
	float getMissileX();
	float getMissileY();
	float getPasMissile();
	int getMissilePower();
	void setCooldown();
	bool isCooldown();
};