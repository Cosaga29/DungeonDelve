#ifndef DEMON_HPP
#define DEMON_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the demon entity, inherits from Entity.

Creates a simple entity that is used to fight the player throughout
the game.

***********************************************************/

#include "Entity.h"

#define DEMON_START_HEALTH 10
#define DEMON_START_ATTACK 5

class Demon : public Entity
{
public:

	Demon(Space* startSpace, int startHealth = DEMON_START_HEALTH, int startAttack = DEMON_START_ATTACK, std::string name = "Demon");


	~Demon();

	int attack() override;

	void defend(int) override;

	bool move(DIRECTION) override;
};

#endif