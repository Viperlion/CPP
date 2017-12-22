#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Dalle.h"
#include "Game.h"

class MyGraphicEngine : public GraphicEngineBase {
private:
	std::vector<Dalle*> *damier;
	Game *game;
	std::vector<Asteroid*> *asteroids;
    char* str_argent;
	char* str_vie;
	char* str_vague;
	char* str_wave_info;
	float x;
	float dx;

public:
	char str[6];
	MyGraphicEngine(std::vector<Dalle*> *argDamier, Game *argGame, std::vector<Asteroid*> *argAsteroids) :
		damier(argDamier),
		game(argGame),
		asteroids(argAsteroids)
        {}
    
    virtual void Draw();

	void drawGameInfos();
	
};
