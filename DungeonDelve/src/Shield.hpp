#ifndef SHIELD_HPP
#define SHIELD_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the shield item, inherits from Item.

The shield item is used to buff the player to be able to kill
the greater demon.

***********************************************************/

#include "Item.hpp"

#define SHIELD_ID			25
#define SHIELD_BOUND		true
#define SHIELD_DEFAULT_USES	-1


class Shield : public Item
{
public:

	bool firstUse;

	Shield(int _id = SHIELD_ID, bool _bound = SHIELD_BOUND, int _uses = SHIELD_DEFAULT_USES,
		std::string desc = "A crimson red shield");

	~Shield();

	virtual void use(Player*);
};

#endif
