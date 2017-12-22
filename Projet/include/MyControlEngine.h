#pragma once
#include "Engine.h"
#include "Dalle.h"
#include "Game.h"

class MyControlEngine : public ControlEngineBase {
protected:
	std::vector<Dalle*> *damier;
	Game *game;
	std::vector<Asteroid*> *asteroids;
	int cursor_pos;
	int old_cursor_pos;
	int active_dalle;
	int old_active_dalle;
public:
	MyControlEngine(std::vector<Dalle*> *argDamier, Game *argGame, std::vector<Asteroid*> *argAsteroids) :
		damier(argDamier),
		game(argGame),
		asteroids(argAsteroids),
		cursor_pos(0),
		old_cursor_pos(-1),
		active_dalle(0),
		old_active_dalle(-1)
	{
		(*damier)[0]->setActive(true);
		(*damier)[0]->changeColor(0.2f, 0.2f, 0.8f);
	}

	virtual void MouseCallback(int button, int state, int x, int y);

	virtual void KeyboardCallback(unsigned char key, int x, int y);

	void checkDalle();

	void selectDalle();

	void checkCreateTurret(unsigned char key);

	void checkTurretModif(unsigned char key);

	void launchWave(unsigned char key);
};
