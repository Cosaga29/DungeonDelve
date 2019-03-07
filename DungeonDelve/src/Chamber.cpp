#include "Chamber.h"



Chamber::Chamber(std::vector<std::string>* prompts) :
	Space('C', prompts)
{
}


Chamber::~Chamber()
{
}

void Chamber::onEnter(Player*)
{
}

void Chamber::update()
{
}

bool Chamber::onExit(Player*)
{
	return true;
}
