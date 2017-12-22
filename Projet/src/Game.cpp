#include "Game.h"
#include "NormalAsteroid.h"

int Game::getLife() {
	return life;
}

int Game::getMoney() {
	return money;
}

int Game::getWave() {
	return wave;
}

void Game::loseLife() {
	life--;
}

void Game::addMoney(int money) {
	this->money += money;
}

void Game::loseMoney(int money) {
	this->money -= money;
}

void Game::nextWave() {
	wave++;
}

bool Game::is_start()
{
	return wave_started;
}

void Game::set_start(bool b) {
	wave_started = b;
}

bool Game::is_game_over() {
	return game_over;
}

void Game::set_game_over() {
	game_over = true;
}

int Game::get_wave_info(int i)
{
	return wave_info[i];
}

void Game::set_wave_info(int i, int val) {
	wave_info[i] = val;
}
