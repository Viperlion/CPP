#include "Dalle.h"

void Dalle::draw() {
	GraphicPrimitives::drawFillRect2D(x, y, width, height, r, g, b);
	GraphicPrimitives::drawOutlinedRect2D(x, y, width, height, 1.0f, 1.0f, 1.0f);
}

void Dalle::changeColor(float r, float g, float b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

void Dalle::drawMenu() {
	if (!b_turret) {
		setMenuAchat();
	}
	else {
		setMenuTurret();
	}
	GraphicPrimitives::drawText2D(menu.getMenuName(), -0.98f, -0.05f, 1.0f, 0.4f, 0.0f);
	for (int i = 0; i < menu.getOptions().size(); i++) {
		GraphicPrimitives::drawText2D(menu.getOptions()[i], -0.9f, -0.15f - i * 0.1f, 1.0f, 0.4f, 0.0f);
	}
}

void Dalle::drawTurret() {
	turret.drawTurret();
}

bool Dalle::isActive() {
	return active;
}

void Dalle::setActive(bool b) {
	active = b;
}

bool Dalle::haveTurret() {
	return b_turret;
}

void Dalle::setTurret(bool b) {
	b_turret = b;
}

Turret Dalle::getTurret() {
	return turret;
}

void Dalle::setMenuAchat() {
	char str[4];
	menu.setMenuName(strcat(new char[14]{ 'C','h','o','i','x',' ','t','o','u','r',' ',':',' ','\0' }, _itoa(500, str, 10)));
	std::vector<char*> new_options;
	new_options.push_back(new char[12]{ '[','1',']',' ','N','o','r','m','a','l','e','\0' });
	new_options.push_back(new char[11]{ '[','2',']',' ','L','o','u','r','d','e','\0' });
	new_options.push_back(new char[11]{ '[','3',']',' ','R','a','p','i','d','e','\0' });
	menu.setOptions(new_options);
}

void Dalle::setMenuTurret() {
	menu.setMenuName(turret.getType());
	std::vector<char*> new_options;
	char str[2];
	new_options.push_back(strcat(new char[7]{ 'L','V','L',' ',':',' ','\0' }, _itoa(turret.getLvl(), str, 10)));
	char str2[3];
	new_options.push_back(strcat(new char[9]{ 'P','o','w','e','r',' ',':',' ','\0' }, _itoa(turret.getPower(), str2, 10)));
	new_options.push_back(strcat(new char[9]{ 'S','p','e','e','d',' ',':',' ','\0' }, _itoa(turret.getSpeed(), str2, 10)));
	char str3[4];
	new_options.push_back(strcat(new char[14]{ 'P','r','i','x',' ','L','v','l','U','p',' ',':',' ','\0' }, _itoa(turret.getLvlUpPrice(), str3, 10)));
	new_options.push_back(strcat(new char[14]{ 'P','r','i','x',' ','V','e','n','t','e',' ',':',' ','\0' }, _itoa(turret.getValue(), str3, 10)));
	new_options.push_back(new char[17]{ '[','1',']',' ','L','v','l','U','p',' ','P','o','w','e','r',' ','\0' });
	new_options.push_back(new char[17]{ '[','2',']',' ','L','v','l','U','p',' ','S','p','e','e','d',' ','\0' });
	new_options.push_back(new char[12]{ '[','3',']',' ','V','e','n','d','r','e',' ','\0' });
	menu.setOptions(new_options);
}

void Dalle::turretSetLourde() {
	turret.setLourde();
}

void Dalle::turretSetRapide() {
	turret.setRapide();
}

void Dalle::turretLvlUpPower() {
	turret.lvlUpPower();
}

void Dalle::turretLvlUpSpeed() {
	turret.lvlUpSpeed();
}

float Dalle::turretGetX()
{
	return turret.getPosX();
}

float Dalle::turretGetY()
{
	return turret.getPosY();
}

void Dalle::sellTurret() {
	turret.init();
	b_turret = false;
}

void Dalle::drawMissile() {
	turret.drawMissile();
}

bool Dalle::isShooting() {
	return turret.haveShoot();
}

void Dalle::setShooting(bool b) {
	turret.setShoot(b);
}

void Dalle::initMissile() {
	turret.missile_init();
}

void Dalle::moveMissile() {
	turret.moveMissile();
}

float Dalle::getMissileX() {
	return turret.getMissileX();
}

float Dalle::getMissileY() {
	return turret.getMissileY();
}

float Dalle::getPasMissile()
{
	return turret.getMissilePas();
}

int Dalle::getMissilePower()
{
	return turret.getMissilePower();
}

void Dalle::setCooldown() {
	turret.setCooldown();
}

bool Dalle::isCooldown()
{
	return turret.isCooldown();
}
