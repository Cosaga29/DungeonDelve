#ifndef ITEM_HPP
#define ITEM_HPP

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

#include <string>
#include <iostream>

class Player;

class Item
{

public:

	int item_id;
	bool bound;
	int uses;
	std::string description;

	Item(int _id, bool _bound, int _uses, std::string desc);

	virtual ~Item();

	virtual void use(Player*) = 0;

	std::string getDescription() const;
	

};

#endif