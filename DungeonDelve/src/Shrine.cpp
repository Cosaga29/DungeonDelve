#include "Shrine.h"



Shrine::Shrine(std::vector<std::string>* prompts) :
	Space('S', prompts)
{
}


Shrine::~Shrine()
{
}

void Shrine::onEnter(Player*)
{
}

void Shrine::update()
{
}

bool Shrine::onExit(Player*)
{
	return true;
}
