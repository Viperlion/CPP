#include <string>
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"

void MyGraphicEngine::Draw(){
	glutReshapeWindow(800, 600);
	drawGameInfos();

	int i;

	for (i = 0; i < damier->size(); i++) {
		(*damier)[i]->draw();
		if ((*damier)[i]->isActive()) {
			(*damier)[i]->drawMenu();
		}
		if ((*damier)[i]->haveTurret()) {
			(*damier)[i]->drawTurret();
		}
	}

	for (i = 0; i < 4; i++) {
		if (game->get_wave_info(i)) {
			GraphicPrimitives::drawFillRect2D(0.96f, 0.8f - 0.2f * i, 0.04f, 0.2f, 0.8f, 0.8f, 0.8f, 0.9f);
		}
	}

	if ((game->is_start())) {
		for (i = 0; i < damier->size(); i++) {
			if ((*damier)[i]->haveTurret() && (*damier)[i]->isShooting()) {
				(*damier)[i]->drawMissile();
			}
		}
	}

	if (asteroids->size() != 0) {
		for (i = 0; i < asteroids->size(); i++) {
			(*asteroids)[i]->draw_asteroid();
		}
	}

}

void MyGraphicEngine::drawGameInfos() {
	str_argent = strcat(new char[10]{ 'A','r','g','e','n','t',' ',':',' ','\0' }, _itoa(game->getMoney(), str, 10));
	str_vie = strcat(new char[7]{ 'V','i','e',' ',':',' ','\0' }, _itoa(game->getLife(), str, 10));
	str_vague = strcat(new char[9]{ 'V','a','g','u','e',' ',':',' ','\0' }, _itoa(game->getWave(), str, 10));

	if (game->is_game_over()) {
		if (game->getLife() <= 0) {
			str_vie = new char[7]{ 'W','a','s','t','e','d','\0' };
		}
		else {
			str_vie = new char[7]{ 'W','i','n','n','e','r','\0' };
		}
	}
	else {
		str_vie = strcat(new char[7]{ 'V','i','e',' ',':',' ','\0' }, _itoa(game->getLife(), str, 10));
	}

	if (game->is_start() && asteroids->size()!=0) {
		str_wave_info = strcat(new char[17]{ 'E','n','e','m','y',' ','r','e','m','a','i','n','s',' ',':',' ','\0' }, _itoa(asteroids->size(), str, 10));
	}
	else {
		str_wave_info = new char[15]{'[','S',']',' ','S','t','a','r','t',' ','w','a','v','e','\0'};
	}

	GraphicPrimitives::drawText2D(str_vie, 0.8f, 0.1f, 1.0f, 0.0f, 0.0f);
	GraphicPrimitives::drawText2D(str_argent, -0.98f, 0.1f, 1.0f, 1.0f, 0.0f);
	GraphicPrimitives::drawText2D(str_vague, -0.1f, 0.1f, 0.9f, 0.9f, 0.9f);
	GraphicPrimitives::drawLine2D(-1.0f, 0.05f, 1.0f, 0.05f, 0.8f, 0.8f, 0.8f);
	GraphicPrimitives::drawText2D(str_wave_info, 0.4f, -0.15f, 1.0f, 0.4f, 0.0f);

}