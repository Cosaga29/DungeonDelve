#include "Connector.h"
#include "Player.h"
#include "Demon.h"



Connector::Connector(std::vector<std::string>* prompts) :
	Space('X', prompts)
{
	std::random_device rngGen;
	int chance = rngGen() % 100;

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

bool Connector::onEnter(Player*)
{
	return true;
}

void Connector::update(Player* pl)
{
	removeDeadEnemies();

	//if any enemies, attack the player
	for (unsigned i = 0; i < enemiesInRoom.size(); i++) {
		pl->defend(enemiesInRoom[i]->attack());
	}
}

bool Connector::onExit(Player*)
{
	if (enemiesInRoom.empty()) {	//player needs to kill the enemies in the room before they can leave
		return true;
	}
	std::cout << "Something is preventing you from leaving!" << std::endl;
	return false;
}

void Connector::getDescription() const
{
	std::random_device rngGen;
	int prompt = rngGen() % CONNECTOR_PROMPTS;
	std::cout << (*prompts)[prompt] << std::endl;
}
