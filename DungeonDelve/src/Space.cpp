#include "Space.h"



void Space::getDescription() const {
	std::cout << (*prompts)[0] << std::endl;
}

char Space::getMapChar() const
{
	return mapChar;
}

Space::Space(char c, std::vector<std::string>* usablePrompts) :
	mapChar(c), prompts(usablePrompts)
{

	top = 0;
	bottom = 0;
	right = 0;
	left = 0;

}


Space::~Space()
{
}