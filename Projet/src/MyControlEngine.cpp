#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include "NormalAsteroid.h"
#include "StrongAsteroid.h"
#include "FastAsteroid.h"
#include "HeavyAsteroid.h"
#include <iostream>

using namespace std;

void MyControlEngine::MouseCallback(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if ((y >= 0) && (y <= 240) && !(game->is_game_over())) {
			cursor_pos = (y / 60) * 10 + (x / 80);
			checkDalle();
			selectDalle();
		}
	}
}

void MyControlEngine::KeyboardCallback(unsigned char key, int x, int y) {

	if (!(game->is_game_over())) {
		if (!(*damier)[active_dalle]->haveTurret()) {
			checkCreateTurret(key);
		}
		else {
			checkTurretModif(key);
		}
		launchWave(key);
	}
}

void MyControlEngine::checkDalle() {

	if (old_cursor_pos != cursor_pos) {

		old_active_dalle = active_dalle;

		int i = cursor_pos / 10;
		if (i == 0) {
			active_dalle = (cursor_pos + 30) % 40;
		}
		else if (i == 1) {
			active_dalle = (cursor_pos + 10) % 40;
		}
		else if (i == 2) {
			active_dalle = (cursor_pos + 30) % 40;
		}
		else {
			active_dalle = (cursor_pos + 10) % 40;
		}
		old_cursor_pos = cursor_pos;
	}
}

void MyControlEngine::selectDalle() {
	int i;

	if (old_active_dalle != -1) {
		i = old_active_dalle / 10;
		if (i == 0) {
			(*damier)[old_active_dalle]->changeColor(0.2f, 0.2f, 0.4f);
		}
		else if (i == 1) {
			(*damier)[old_active_dalle]->changeColor(0.4f, 0.2f, 0.2f);
		}
		else if (i == 2) {
			(*damier)[old_active_dalle]->changeColor(0.2f, 0.4f, 0.2f);
		}
		else {
			(*damier)[old_active_dalle]->changeColor(0.4f, 0.4f, 0.2f);
		}
		(*damier)[old_active_dalle]->setActive(false);
	}

	if (active_dalle != -1) {
		i = active_dalle / 10;
		if (i == 0) {
			(*damier)[active_dalle]->changeColor(0.2f, 0.2f, 0.8f);
		}
		else if (i == 1) {
			(*damier)[active_dalle]->changeColor(0.8f, 0.2f, 0.2f);
		}
		else if (i == 2) {
			(*damier)[active_dalle]->changeColor(0.2f, 0.8f, 0.2f);
		}
		else {
			(*damier)[active_dalle]->changeColor(0.8f, 0.8f, 0.2f);
		}
		(*damier)[active_dalle]->setActive(true);
	}
	
}

void MyControlEngine::checkCreateTurret(unsigned char key) {
	if (game->getMoney() >= 500) {
		if (key == '1') {
			(*damier)[active_dalle]->setTurret(true);
			game->loseMoney(500);
		}
		else if (key == '2') {
			(*damier)[active_dalle]->turretSetLourde();
			(*damier)[active_dalle]->setTurret(true);
			game->loseMoney(500);
		}
		else if (key == '3') {
			(*damier)[active_dalle]->turretSetRapide();
			(*damier)[active_dalle]->setTurret(true);
			game->loseMoney(500);
		}
	}
}

void MyControlEngine::checkTurretModif(unsigned char key) {
	if (key == '1') {
		if ((game->getMoney() >= (*damier)[active_dalle]->getTurret().getLvlUpPrice())
			&& (*damier)[active_dalle]->getTurret().getLvlUpPrice() < 250) {
			game->loseMoney((*damier)[active_dalle]->getTurret().getLvlUpPrice());
			(*damier)[active_dalle]->turretLvlUpPower();
		}
	}
	else if (key == '2') {
		if ((game->getMoney() >= (*damier)[active_dalle]->getTurret().getLvlUpPrice())
		&& (*damier)[active_dalle]->getTurret().getLvlUpPrice() < 250) {
			game->loseMoney((*damier)[active_dalle]->getTurret().getLvlUpPrice());
			(*damier)[active_dalle]->turretLvlUpSpeed();
		}
	}
	else if (key == '3') {
		game->addMoney((*damier)[active_dalle]->getTurret().getValue());
		(*damier)[active_dalle]->sellTurret();
	}
}

void MyControlEngine::launchWave(unsigned char key) {
	if ((key == 's' || key == 'S') && !(game->is_start())) {
		int i;

		// LEVEL 1
		if (game->getWave() == 1) {
			for (i = 0; i < 6; i++) {
				asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.8f));
			}
		}

		// LEVEL 2
		if (game->getWave() == 2) {
			for (i = 0; i < 6; i++) {
				asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.6f));
			}
		}

		// LEVEL 3
		if (game->getWave() == 3) {
			for (i = 0; i < 6; i++) {
				asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.4f));
			}
		}

		// LEVEL 4
		if (game->getWave() == 4) {
			for (i = 0; i < 6; i++) {
				asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.2f));
			}
		}

		game->set_start(true);

		// LEVEL 5
		if (game->getWave() == 5) {
			for (i = 0; i < 6; i++) {
				asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.8f));
				asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.6f));
			}
		}

		// LEVEL 6
		if (game->getWave() == 6) {
			for (i = 0; i < 6; i++) {
				asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.4f));
				asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.2f));
			}
		}

		// LEVEL 7
		if (game->getWave() == 7) {
			for (i = 0; i < 10; i++) {
				if (i % 2 == 0) {
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.8f));
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.4f));
				}
				else {
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.3f, 0.8f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.4f));
				}
			}
		}

		// LEVEL 8
		if (game->getWave() == 8) {
			for (i = 0; i < 10; i++) {
				if (i % 2 == 0) {
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.6f));
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.2f));
				}
				else {
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.3f, 0.6f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.2f));
				}
			}
		}

		// LEVEL 9
		if (game->getWave() == 9) {
			for (i = 0; i < 10; i++) {
				if (i % 2 == 0) {
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.8f));
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.2f, 0.2f));
				}
				else {
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.3f, 0.8f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.2f));
				}
			}
		}

		// LEVEL 10
		if (game->getWave() == 10) {
			for (i = 0; i < 10; i++) {
				if (i % 2 == 0) {
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.6f));
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.2f, 0.4f));
				}
				else {
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.3f, 0.6f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.4f));
				}
			}
		}

		// LEVEL 11
		if (game->getWave() == 11) {
			for (i = 0; i < 11; i++) {
				if (i % 3 == 0) {
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.8f));
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.6f));
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.4f));
				}
				else if (i % 3 == 1) {
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.8f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.6f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.4f));
				}
				else {
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.5f, 0.8f));
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.5f, 0.6f));
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.5f, 0.4f));
				}
			}
		}

		// LEVEL 12
		if (game->getWave() == 12) {
			for (i = 0; i < 11; i++) {
				if (i % 3 == 0) {
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.8f));
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.6f));
					asteroids->push_back(new NormalAsteroid(1.1f + i * 0.2f, 0.2f));
				}
				else if (i % 3 == 1) {
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.8f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.6f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.2f));
				}
				else {
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.8f));
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.6f));
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.2f));
				}
			}
		}

		// LEVEL 13
		if (game->getWave() == 13) {
			for (i = 0; i < 9; i++) {
				if (i % 3 == 0) {
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.6f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.4f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.2f, 0.2f));
				}
				else if (i % 3 == 1) {
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.6f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.4f));
					asteroids->push_back(new StrongAsteroid(1.1f + i * 0.3f, 0.2f));
				}
				else {
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.6f));
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.4f));
					asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.2f));
				}
			}
		}

		// LEVEL 14
		if (game->getWave() == 14) {
			for (i = 0; i < 12; i++) {
				asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.8f));
				asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.6f));
				asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.4f));
				asteroids->push_back(new FastAsteroid(1.1f + i * 0.5f, 0.2f));
			}
		}

		// LEVEL 15
		if (game->getWave() == 15) {
			for (i = 0; i < 3; i++) {
				asteroids->push_back(new HeavyAsteroid(1.1f + i * 0.5f, 0.8f));
				asteroids->push_back(new HeavyAsteroid(1.1f + i * 0.5f, 0.6f));
				asteroids->push_back(new HeavyAsteroid(1.1f + i * 0.5f, 0.4f));
				asteroids->push_back(new HeavyAsteroid(1.1f + i * 0.5f, 0.2f));
			}
		}
	}
}
