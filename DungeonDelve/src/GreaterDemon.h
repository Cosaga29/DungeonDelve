#ifndef GREATERDEMON_HPP
#define GREATERDEMON_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the GreaterDemon class. The class is
a boss character that the player must defeat to get the key to
leave the game.

***********************************************************/

#include "Entity.h"

#define GDEMON_START_HEALTH 500
#define GDEMON_START_ATTACK 25

class GreaterDemon : public Entity
{
public:
	GreaterDemon(Space* startSpace, int startHealth = GDEMON_START_HEALTH, int startAttack = GDEMON_START_ATTACK, std::string name = "Greater Demon");
	
	~GreaterDemon();

	int attack() override;

	void defend(int) override;

	bool move(DIRECTION) override;
};

#endif