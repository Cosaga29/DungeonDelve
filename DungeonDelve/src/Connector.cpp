/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Connector space, inherits from Space.
The connector space is a generic place on the board. Enemies are allowed
to randomly spawn along with items.

Constructor spawns random enemies and items

***********************************************************/

#include "Connector.hpp"
#include "Player.hpp"
#include "Demon.hpp"



Connector::Connector(std::vector<std::string>* prompts) :
	Space('X', prompts)
{
	//create random device to generate numbers
	std::random_device rngGen; //device used for RNG generation

	int chance = rngGen() % 100;	//generate between 0-99

	if (chance > 85) { //15% chance to spawn a demon
		enemiesInRoom.push_back(std::unique_ptr<Entity>(new Demon(this)));
	}

	chance = rand() % 100;
	if (chance > 85) {	//15% chance to spawn a health potion
		_inventory.push_back(std::unique_ptr<Item>(new HealthPotion()));
	}

	chance = rand() % 100;
	if (chance > 85) {	//15% chance to spawn a energy potion
		_inventory.push_back(std::unique_ptr<Item>(new EnergyPotion()));
	}

}


Connector::~Connector()
{
}

/*
Room has no onEnter method that is called
*/
bool Connector::onEnter(Player*)
{
	return true;
}

/*
Removes any dead enemies at the end of the update-cycle
*/
void Connector::update(Player* pl)
{
	removeDeadEnemies();

	//if any enemies, attack the player
	for (unsigned i = 0; i < enemiesInRoom.size(); i++) {
		pl->defend(enemiesInRoom[i]->attack());
	}
}

/*
Ensures player cannot leave if any enemies are in the room
*/
bool Connector::onExit(Player*)
{
	if (enemiesInRoom.empty()) {	//player needs to kill the enemies in the room before they can leave
		return true;
	}
	std::cout << "Something is preventing you from leaving!" << std::endl;
	return false;
}

/*
Randomly return a prompt to display to the character
*/
void Connector::getDescription() const
{
	std::random_device rngGen; //device used for RNG generation
	int prompt = rngGen() % CONNECTOR_PROMPTS;
	std::cout << (*prompts)[prompt] << std::endl;
}
