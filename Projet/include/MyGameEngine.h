#pragma once

#include "Engine.h"
#include "GameEngineBase.h"
#include "Dalle.h"
#include "Game.h"

class MyGameEngine : public GameEngineBase {
private:
	std::vector<Dalle*> *damier;
	Game *game;
	std::vector<Asteroid*> *asteroids;

public:
	MyGameEngine(std::vector<Dalle*> *argDamier, Game *argGame, std::vector<Asteroid*> *argAsteroids):
		damier(argDamier),
		game(argGame),
		asteroids(argAsteroids)
		{
	}
    virtual void idle();	// == Simulate
	void changeWave();
};

