#include "StartRoom.h"



StartRoom::StartRoom(std::vector<std::string>* prompts) :
	Space('P', prompts)
{

	_inventory.push_back(std::unique_ptr<Item>(new HealthPotion));
	_inventory.push_back(std::unique_ptr<Item>(new EnergyPotion));

}


StartRoom::~StartRoom()
{
}

bool StartRoom::onEnter(Player*)
{

	//print tutorial prompts
	std::cout << "Welcome to the game! Here is a short tutorial: \n\n" <<
		"\tThe goal of the game is to go to all the shrines and collect equipment to be able\n" <<
		"\tto kill the demon in the chamber. You must 'use' the items you get from the shinres.\n" <<
		"\tThe demon in the chamber will drop a key which will allow you to exit the game.\n\n" << 
		"\tYou can perform any action in accordance to your action prompts.\n" <<
		"\tI recommend that you take and use your potions (Both energy and healing)\n" <<
		"\tENEMIES WILL NOT LET YOU LEAVE THE ROOM, YOU MUST KILL THEM FIRST\n"       <<
		"\tBefore you head to the chamber on the map, you should go to the shrines first, or it will end badly. \n" <<
		"\tBe sure to 'use' any item that you might pick up at the shrines, you'll thank me later.\n"  <<
		"\tIf you would like to see the map and this prompt again, please re-enter the room. \n" <<  
		"\tMonsters and items are spawned randomly, except for the monster in the chamber.\n" <<
		"\tYou must kill the monster in the chamber to get the key to leave.\n" <<
		"\tIt's dangerous to go alone, so here's some starting potions.\n" << 
		"\tAlso, here is the starting map, if you need to see it again, leave and enter:\n" << std::endl;

	//print map
	std::cout <<
		"----------------\n"
		"|   S X        |\n"
		"|     X X X    |\n"
		"| P X X   X    |\n"
		"|     X   X E  |\n"
		"| S X X        |\n"
		"|     X        |\n"
		"|     X X C    |\n" 
		"----------------\n\n" 
		"P - Starting Location \t   S - Shrine Location   \tC - Chamber Location  \tE - Exit\n" << std::endl;
		//"S - Shrine Location   \n"
		//"C - Chamber Location  \n"
		//"E - Exit              \n\n" << std::endl;

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
