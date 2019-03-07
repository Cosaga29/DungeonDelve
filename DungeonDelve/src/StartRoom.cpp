#include "StartRoom.h"



StartRoom::StartRoom(std::vector<std::string>* prompts) :
	Space('P', prompts)
{

	_inventory.push_back(std::unique_ptr<Item>(new HealthPotion));
}


StartRoom::~StartRoom()
{
}

bool StartRoom::onEnter(Player*)
{
	std::cout << "Welcome to the game. " << std::endl;
	return true;
}

void StartRoom::update(Player*)
{
}

bool StartRoom::onExit(Player*)
{
	return true;
}
