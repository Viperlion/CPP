#include <iostream>

#include "Engine.h"
#include "ControlEngineBase.h"
#include "GameEngineBase.h"
#include "GraphicEngineBase.h"
#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include "MyGraphicEngine.h"
#include "Dalle.h"
#include "Game.h"

using namespace std;

int main(int argc, char* argv[]){
    Engine e(argc,argv);

	float r = 0.2f;
	float g = 0.2f;
	float b = 0.4f;
    
	std::vector<Asteroid*> asteroids;
	std::vector<Dalle*> damier;
	Game game;

	for (int i = 0; i < 4; i++) {
		if (i == 1) {
			b = r;
			r = 0.4f;
		}
		else if (i == 2) {
			g = r;
			r = 0.2f;
		}
		else if (i == 3) {
			r = g;
		}
		for (int j = 0; j < 10; j++) {
			damier.push_back(new Dalle(- 1.0f + 0.2f * j, 0.2f * i + 0.2f, r, g, b));
		}
	}
    
    GraphicEngineBase* ge = new MyGraphicEngine(&damier, &game, &asteroids);
    GameEngineBase* gme = new MyGameEngine(&damier, &game, &asteroids);
    ControlEngineBase* ce = new MyControlEngine(&damier, &game, &asteroids);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
