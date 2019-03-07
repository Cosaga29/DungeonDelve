#include "StartRoom.h"



StartRoom::StartRoom(std::vector<std::string>* prompts) :
	Space('P', prompts)
{

	_inventory.push_back(std::unique_ptr<Item>(new HealthPotion));
}


StartRoom::~StartRoom()
{
}

void StartRoom::onEnter(Player*)
{
	std::cout << "Welcome to the game. " << std::endl;
}

void StartRoom::update()
{
}

bool StartRoom::onExit(Player*)
{
	return true;
}
