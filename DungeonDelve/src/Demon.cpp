#include "Demon.h"



Demon::Demon(Space* startSpace, int startHealth, int startAttack, std::string name) :
	Entity(startSpace, startHealth, startAttack, name)
{
}


Demon::~Demon()
{
}

int Demon::attack()
{
	return attack_power;
}

void Demon::defend(int damage)
{
	health -= damage;
	std::cout << "\n\nYou hit the demon for " << damage << " damage!" <<  "[" << health << "] remains\n" << std::endl;
}

bool Demon::move(DIRECTION)
{
	return false;
}
