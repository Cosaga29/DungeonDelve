#include "Shrine.h"



Shrine::Shrine(std::vector<std::string>* prompts) :
	Space('S', prompts)
{
}


Shrine::~Shrine()
{
}

bool Shrine::onEnter(Player*)
{
	return true;
}

void Shrine::update(Player*)
{
}

bool Shrine::onExit(Player*)
{
	return true;
}
