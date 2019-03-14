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
	std::cout << "Welcome to the game! Here is a short tutorial: \n" <<
		"\tYou can perform any action in accordance to your inventory prompts.\n" <<
		"\tI recommend that you use your potions (Both energy and healing)\n" <<
		"\tBefore you head to the chamber on the map, you should go to the shrines first, or it will end badly. \n" <<
		"\tBe sure to 'use' any item that you might pick up at the shrines, you'll thank me later.\n"  <<
		"\tIf you would like to see the map and this prompt again, please re-enter the room. \n" <<  
		"\tMonsters and items are spawned randomly, except for the monster in the chamber.\n" <<
		"\tIt's dangerous to go alone, so here's some starting potions. " << std::endl;

	return true;
}

void StartRoom::update(Player*)
{
}

bool StartRoom::onExit(Player*)
{
	std::cout << "Good luck! Enjoy the game." << std::endl;
	return true;
}
