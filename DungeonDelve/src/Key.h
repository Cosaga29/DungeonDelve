#pragma once
#include "Item.h"

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Item super class. Items are used
by the player to interact with the world and modify the player class.

***********************************************************/

#define KEY_ID				20
#define KEY_BOUND			true
#define KEY_DEFAULT_USES	-1


class Key : public Item
{
public:


	Key(int _id = KEY_ID, bool _bound = KEY_BOUND, int _uses = KEY_DEFAULT_USES, 
		std::string desc = "A black metal key");


	~Key();

	void use(Player*) override;

};

