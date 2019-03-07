#include "Space.h"
#include "Entity.h"
#include "Player.h"



void Space::getDescription() const {
	std::cout << (*prompts)[0] << std::endl;
}

void Space::getItems() const
{
	std::cout << "Items in the room: \n";
	for (auto it = _inventory.begin(); it != _inventory.end(); it++) {
		std::cout << "\t" << (*it)->getDescription() << "\n";
	}
	std::cout << "\n" << std::endl;
}

void Space::getEnemies() const
{
	std::cout << "Enemies in the room: \n";
	if (enemiesInRoom.empty()) {
		std::cout << "None! \n" << std::endl;
		return;
	}

	for (auto it = enemiesInRoom.begin(); it != enemiesInRoom.end(); it++) {
		std::cout << (*it)->name << std::endl;
	}
	std::cout << "\n" << std::endl;
}

char Space::getMapChar() const
{
	return mapChar;
}

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