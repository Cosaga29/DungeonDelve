#include "GreaterDemon.h"



GreaterDemon::GreaterDemon(Space* startSpace, int startHealth, int startAttack, std::string name) :
	Entity(startSpace, startHealth, startAttack, name)
{
}


GreaterDemon::~GreaterDemon()
{
}

int GreaterDemon::attack()
{
	return attack_power;
}

void GreaterDemon::defend(int damage)
{
	health -= damage;
	std::cout << "\n\nYou hit the demon for " << damage << " damage!" << "[" << health << "] remains\n" << std::endl;
}

bool GreaterDemon::move(DIRECTION)
{
	return false;
}
