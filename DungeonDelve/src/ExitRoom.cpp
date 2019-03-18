/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the exitroom. The exitRoom is the final room
for the player to enter. The room checks to make sure the player
has the key on entry. If the player doesnt have the key, it sets
the player's position to the previous room.

Player must kill greater dmeon to spawn the key

***********************************************************/

#include "ExitRoom.hpp"
#include "Player.hpp"
#include "Key.hpp"


/*
Consturctor
*/
ExitRoom::ExitRoom(std::vector<std::string>* prompts) :
	Space('E', prompts)
{
}


ExitRoom::~ExitRoom()
{
}

/*
Searches through the players inventory to see if they have a key. 
If the player does have a key, then the player is allowed entry.
*/
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

/*
Exit room has no update function
*/
void ExitRoom::update(Player*)
{
}

/*
Remind player to exit on leaving the room
*/
bool ExitRoom::onExit(Player* pl) //check if player as a key
{
	std::cout << "Make sure the leave the game with 'Exit' " << std::endl;
	return true;
}
