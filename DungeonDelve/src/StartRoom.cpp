#include "StartRoom.h"



StartRoom::StartRoom(std::vector<std::string>* prompts) :
	Space('P', prompts)
{
}


StartRoom::~StartRoom()
{
}

void StartRoom::onEnter()
{
	std::cout << "Welcome to the game. " << std::endl;
}

void StartRoom::onPlayerAction()
{
}

void StartRoom::onExit()
{
}
