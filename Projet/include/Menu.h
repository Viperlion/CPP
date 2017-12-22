#pragma once
#include "GraphicPrimitives.h"

class Menu {

private:
	char* menuName;
	std::vector<char*> options;

public:
	void setMenuName(char* name);

	void setOptions(std::vector<char*> new_options);

	char* getMenuName();

	std::vector<char*> getOptions();

};