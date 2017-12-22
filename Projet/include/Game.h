#pragma once
#include "GraphicPrimitives.h"
#include "Asteroid.h"

class Game {
protected :
	int life;
	int money;
	int wave;
	bool wave_started;
	bool game_over;
	int wave_info[4];

public:
	Game() :
		life(5), money(1000),
		wave(1), wave_info(),wave_started(false),
		game_over(false) {
		wave_info[0] = 1;
		wave_info[1] = 0;
		wave_info[2] = 0;
		wave_info[3] = 0;
	}

	int getLife();

	void loseLife();

	int getMoney();

	void addMoney(int money);

	void loseMoney(int money);

	int getWave();

	void nextWave();

	bool is_start();

	void set_start(bool b);

	bool is_game_over();

	void set_game_over();

	int get_wave_info(int i);

	void set_wave_info(int i, int val);
};
