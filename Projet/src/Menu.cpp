#include "Menu.h"

void Menu::setMenuName(char* name) {
	menuName = name;
}
void Menu::setOptions(std::vector<char*> new_options) {
	options = new_options;
}
char* Menu::getMenuName() {
	return menuName;
}

std::vector<char*> Menu::getOptions() {
	return options;
}

