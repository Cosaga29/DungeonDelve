#include "ExitRoom.h"
#include "Player.h"
#include "Key.h"



ExitRoom::ExitRoom(std::vector<std::string>* prompts) :
	Space('E', prompts)
{
}


ExitRoom::~ExitRoom()
{
}

bool ExitRoom::onEnter(Player* pl)
{
	//search through players inventory
	for (unsigned i = 0; i < pl->_inventory.size(); i++) {
		if (pl->_inventory[i]->item_id == KEY_ID) {
			return true; //player can leave, they have the key
		}
	}
	return false;

}

void ExitRoom::update(Player*)
{
}

bool ExitRoom::onExit(Player* pl) //check if player as a key
{
	return true;
}
