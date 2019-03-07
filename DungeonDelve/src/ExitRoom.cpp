#include "ExitRoom.h"



ExitRoom::ExitRoom(std::vector<std::string>* prompts) :
	Space('E', prompts)
{
}


ExitRoom::~ExitRoom()
{
}

void ExitRoom::onEnter(Player*)
{
}

void ExitRoom::update()
{
}

bool ExitRoom::onExit(Player*)
{
	return true;
}
