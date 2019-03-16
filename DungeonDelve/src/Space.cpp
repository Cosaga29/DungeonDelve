/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Space class. The space class
is a superclass that is used by the game glass to model locations
the player can visit.

Each space two contains, one for entities in the room and one
for items in the room.

***********************************************************/

#include "Space.h"
#include "Entity.h"
#include "Player.h"


/*
Return first description in prompt list
*/
void Space::getDescription() const {
	std::cout << (*prompts)[0] << std::endl;
}

/*
Loop through and list all the items currently in the room
*/
void Space::getItems() const
{
	std::cout << "Items in the room: \n";
	for (auto it = _inventory.begin(); it != _inventory.end(); it++) {
		std::cout << "\t" << (*it)->getDescription() << "\n";
	}
	std::cout << "\n" << std::endl;
}

/*
Loop through and list all the entities in the room
*/
void Space::getEnemies() const
{
	std::cout << "Enemies in the room: \n";		//check if any entities are in the room
	if (enemiesInRoom.empty()) {
		std::cout << "None! \n" << std::endl;
		return;
	}

	for (auto it = enemiesInRoom.begin(); it != enemiesInRoom.end(); it++) {	//loop through entities
		std::cout << (*it)->name << std::endl;
	}
	std::cout << "\n" << std::endl;
}

/*
Function that deletes any enemy in the room that isDead (Has health <=0)
*/
void Space::removeDeadEnemies() 
{
	if (enemiesInRoom.empty()) {
		return;
	}

	for (unsigned i = 0; i < enemiesInRoom.size(); i++) {
		if (enemiesInRoom[i]->isDead()) {

			if (enemiesInRoom[i]->_inventory.empty()) {
				enemiesInRoom.erase(enemiesInRoom.begin() + i);
			}

		}
	}
	
}

/*
Returns current character designating the room type
*/
char Space::getMapChar() const
{
	return mapChar;
}

/*
Constructor that initializes all space pointers to null
*/
Space::Space(char c, std::vector<std::string>* usablePrompts) :
	mapChar(c), prompts(usablePrompts)
{

	top = 0;
	bottom = 0;
	right = 0;
	left = 0;

}


Space::~Space()
{
}