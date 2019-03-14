#include "Chamber.h"
#include "GreaterDemon.h"
#include "Player.h"
#include "Key.h"



Chamber::Chamber(std::vector<std::string>* prompts) :
	Space('C', prompts)
{
	enemiesInRoom.push_back(std::unique_ptr<Entity>(new GreaterDemon(this)));
	keySpawned = false;
}


Chamber::~Chamber()
{
}

bool Chamber::onEnter(Player*)
{
	return true;
}

void Chamber::update(Player* pl)
{
	removeDeadEnemies();

	//if any enemies, attack the player
	for (unsigned i = 0; i < enemiesInRoom.size(); i++) {
		pl->defend(enemiesInRoom[i]->attack());
	}

	//make the player take extra damage if they dont have the bottle

	if (enemiesInRoom.empty() && !keySpawned) { //if player has defeated enemy and key hasnt spawned, spawn key
		//player defeated the entity, spawn a key
		std::cout << "You defeated the greater demon!!" << std::endl;
		std::cout << "You hear something hit the floor with a 'ting'" << std::endl;
		this->_inventory.push_back(std::unique_ptr<Item>(new Key()));
		keySpawned = true;
	}
}

bool Chamber::onExit(Player*)
{
	if (enemiesInRoom.empty()) {	//player needs to kill the enemies in the room before they can leave
		return true;
	}
	std::cout << "Something is preventing you from leaving!" << std::endl;
	return false;
}
