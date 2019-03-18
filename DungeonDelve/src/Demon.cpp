/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the demon entity, inherits from Entity.

Creates a simple entity that is used to fight the player throughout
the game.

***********************************************************/

#include "Demon.hpp"



Demon::Demon(Space* startSpace, int startHealth, int startAttack, std::string name) :
	Entity(startSpace, startHealth, startAttack, name)
{
}


Demon::~Demon()
{
}

/*
Function to simulate an attack, simply returns ~5damage
*/
int Demon::attack()
{
	return attack_power;
}

/*
Method for demon to defend against attacks from the player
*/
void Demon::defend(int damage)
{
	health -= damage;
	std::cout << "\n\nYou hit the demon for " << damage << " damage!" <<  "[" << health << "] remains\n" << std::endl;
}

/*
Move method not used for demon class
*/
bool Demon::move(DIRECTION)
{
	return false;
}
