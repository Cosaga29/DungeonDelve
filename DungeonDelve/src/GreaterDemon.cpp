/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the GreaterDemon class. The class is
a boss character that the player must defeat to get the key to
leave the game.

***********************************************************/

#include "GreaterDemon.hpp"


/*
Constructor
*/
GreaterDemon::GreaterDemon(Space* startSpace, int startHealth, int startAttack, std::string name) :
	Entity(startSpace, startHealth, startAttack, name)
{
}


GreaterDemon::~GreaterDemon()
{
}

/*
Function to simulate an attack, simply returns ~5damage
*/
int GreaterDemon::attack()
{
	return attack_power;
}

/*
Method for demon to defend against attacks from the player
*/
void GreaterDemon::defend(int damage)
{
	health -= damage;
	std::cout << "\n\nYou hit the demon for " << damage << " damage!" << "[" << health << "] remains\n" << std::endl;
}

/*
Move method not used for demon class
*/
bool GreaterDemon::move(DIRECTION)
{
	return false;
}
