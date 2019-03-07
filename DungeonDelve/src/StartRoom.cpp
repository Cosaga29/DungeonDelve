#include "StartRoom.h"



StartRoom::StartRoom(std::vector<std::string>* prompts) :
	Space('P', prompts)
{

	_inventory.push_back(std::unique_ptr<Item>(new HealthPotion));
}


StartRoom::~StartRoom()
{
}

void StartRoom::onEnter()
{
	std::cout << "Welcome to the game. " << std::endl;
}

void StartRoom::update()
{
}

void StartRoom::onExit()
{
}
