/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Item super class. Items are used
by the player to interact with the world and modify the player class.

Every item has an id, so it can be recongnized by the game engine.
Every item can be bound or not bound, bound items cannot be dropped.

Consumable items have a limited number of uses.

***********************************************************/

#include "Item.h"
#include "Player.h"


/*Constructor*/
Item::Item(int _id, bool _bound, int _uses, std::string desc) :
	item_id(_id), bound(_bound), uses(_uses), description(desc)
{
}

/*Destructor*/
Item::~Item()
{
}

/*
Returns item description
*/
std::string Item::getDescription() const
{
	return description;
}
