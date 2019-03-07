#include "Connector.h"
#include "Player.h"



Connector::Connector(std::vector<std::string>* prompts) :
	Space('X', prompts)
{
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
