#include "MyGameEngine.h"
#include "NormalAsteroid.h"

void MyGameEngine::idle(){
	
	if (!(game->is_game_over())) {

		if (game->is_start()) {
			int i;

			// Turret's shot
			for (i = 0; i < damier->size(); i++) {

				//Collision missile asteroïd
				for (int j = 0; j < asteroids->size(); j++) {
					if (((*damier)[i]->turretGetY() - 0.1f >= (*asteroids)[j]->getPosY() - 0.05f) &&
						((*damier)[i]->turretGetY() - 0.1f <= (*asteroids)[j]->getPosY() + 0.05f &&
						(*damier)[i]->haveTurret())) {
						if (((*damier)[i]->turretGetX() >= (*asteroids)[j]->getPosX()) &&
							((*damier)[i]->turretGetX() <= (*asteroids)[j]->getPosX() + (*asteroids)[j]->getPasAsteroid())) {
							(*asteroids)[j]->loseLife(16);
							(*damier)[i]->sellTurret();
						}
					}
				}

				if ((*damier)[i]->haveTurret()) {

					if (!((*damier)[i]->isCooldown())) {

						if (!((*damier)[i]->isShooting())) {
							(*damier)[i]->setShooting(true);
							(*damier)[i]->initMissile();
						}

						(*damier)[i]->moveMissile();
						//Collision missile asteroïd
						for (int j = 0; j < asteroids->size(); j++) {
							if (((*damier)[i]->getMissileY() - 0.1f >= (*asteroids)[j]->getPosY() - 0.05f) &&
								((*damier)[i]->getMissileY() - 0.1f <= (*asteroids)[j]->getPosY() + 0.05f)) {
								if (((*damier)[i]->getMissileX() >= (*asteroids)[j]->getPosX()) &&
									((*damier)[i]->getMissileX() - 3 * (*damier)[i]->getPasMissile() <= (*asteroids)[j]->getPosX())) {

									(*asteroids)[j]->loseLife((*damier)[i]->getMissilePower());
									(*damier)[i]->setCooldown();
								}
							}
						}
						if ((*damier)[i]->getMissileX() > 1.0f) {
							(*damier)[i]->setCooldown();
						}
					}
				}
			}

			if (asteroids->size() != 0) {
				for (i = 0; i < asteroids->size(); i++) {
					if ((*asteroids)[i]->checkAlive()) {
						(*asteroids)[i]->move();
						if ((*asteroids)[i]->getPosX() < -1.0f) {
							game->loseLife();
							asteroids->erase(asteroids->begin() + i);
							if (game->getLife() <= 0) {
								game->set_game_over();
							}
						}
					}
					else {
						game->addMoney(75);
						asteroids->erase(asteroids->begin() + i);
					}
				}
			}
			else {
				if (game->getWave() < 15) {
					changeWave();
				}
				else {
					game->set_game_over();
				}
				game->set_start(false);
			}
		}
	}
}

void MyGameEngine::changeWave() {
	game->nextWave();

	int i;
	for (i = 0; i < damier->size(); i++) {
		if ((*damier)[i]->haveTurret()) {
			(*damier)[i]->initMissile();
		}
	}

	if (game->getWave() == 2) {
		game->set_wave_info(0, 0);
		game->set_wave_info(1, 1);
	}

	if (game->getWave() == 3) {
		game->set_wave_info(1, 0);
		game->set_wave_info(2, 1);
	}

	if (game->getWave() == 4) {
		game->set_wave_info(2, 0);
		game->set_wave_info(3, 1);
	}

	if (game->getWave() == 5) {
		game->set_wave_info(3, 0);
		game->set_wave_info(0, 1);
		game->set_wave_info(1, 1);
	}

	if (game->getWave() == 6) {
		game->set_wave_info(0, 0);
		game->set_wave_info(1, 0);
		game->set_wave_info(2, 1);
		game->set_wave_info(3, 1);
	}

	if (game->getWave() == 7) {
		game->set_wave_info(0, 1);
		game->set_wave_info(2, 1);
		game->set_wave_info(3, 0);
	}

	if (game->getWave() == 8) {
		game->set_wave_info(0, 0);
		game->set_wave_info(1, 1);
		game->set_wave_info(2, 0);
		game->set_wave_info(3, 1);
	}

	if (game->getWave() == 9) {
		game->set_wave_info(0, 1);
		game->set_wave_info(1, 0);
	}

	if (game->getWave() == 10) {
		game->set_wave_info(0, 0);
		game->set_wave_info(1, 1);
		game->set_wave_info(2, 1);
		game->set_wave_info(3, 0);
	}

	if (game->getWave() == 11) {
		game->set_wave_info(0, 1);
		game->set_wave_info(1, 1);
		game->set_wave_info(2, 1);
	}

	if (game->getWave() == 12) {
		game->set_wave_info(2, 0);
		game->set_wave_info(3, 1);
	}

	if (game->getWave() == 13) {
		game->set_wave_info(0, 0);
		game->set_wave_info(2, 1);
	}

	if (game->getWave() == 14) {
		game->set_wave_info(0, 1);
	}
}

