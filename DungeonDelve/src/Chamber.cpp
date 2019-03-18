/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the chamber space, inherits from Space.
The chamber is used in the dungeondelve to implement a boss room.

Constructor spawns an entity that must be defeated for a key

***********************************************************/

#include "Chamber.hpp"
#include "GreaterDemon.hpp"
#include "Player.hpp"
#include "Key.hpp"


/*
Consturctor, creates a GreaterDemon object and sets the flag 
for the key being spawned to false.
*/
Chamber::Chamber(std::vector<std::string>* prompts) :
	Space('C', prompts)
{
	enemiesInRoom.push_back(std::unique_ptr<Entity>(new GreaterDemon(this)));
	keySpawned = false;
}


Chamber::~Chamber()
{
}

/*
Chamber does not have any affect for onEnter
*/
bool Chamber::onEnter(Player*)
{
	return true;
}

/*
For each game tick, the game checks to remove dead enemies from the room.
If there are any enemies, the room handles the attacks on the player.

The game also checks to see if the player has the bottle item, if they dont,
they take extra damage since the fight would be incredibly drawn out.
*/
void Chamber::update(Player* pl)
{
	removeDeadEnemies();

	//if any enemies, attack the player
	for (unsigned i = 0; i < enemiesInRoom.size(); i++) {
		pl->defend(enemiesInRoom[i]->attack());

		//check if player doesn't have bottled rage buff
		if (!pl->bottleBuff) {
			std::cout << "The chamber is incredibly hot. You are suffering extra damage." << std::endl;
			pl->defend(333);
		}

	}

	if (enemiesInRoom.empty() && !keySpawned) { //if player has defeated enemy and key hasnt spawned, spawn key
		//player defeated the entity, spawn a key
		std::cout << "You defeated the greater demon!!" << std::endl;
		std::cout << "You hear something hit the floor with a 'ting'" << std::endl;
		this->_inventory.push_back(std::unique_ptr<Item>(new Key()));
		keySpawned = true;
	}






}

/*
Prevent the player from leaving if there is enemy in the room
*/
bool Chamber::onExit(Player*)
{
	if (enemiesInRoom.empty()) {	//player needs to kill the enemies in the room before they can leave
		return true;
	}
	std::cout << "Something is preventing you from leaving!" << std::endl;
	return false;
}
