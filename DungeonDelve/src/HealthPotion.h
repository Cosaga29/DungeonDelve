#ifndef HP_HPP
#define HP_HPP


/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the HealthPotion class, inherits from Item.

Defines an item that can be used by the player to restore their health
pool. The potions have 3 uses that restore 20 health each, up to 60 energy.

***********************************************************/


#include "Item.h"

#define HP_ID			15
#define HP_BOUND		false
#define HP_DEFAULT_USES	3
#define HP_RESTORE		20


class HealthPotion : public Item
{
public:

	//Item::Item(int _id, bool _bound, int _uses, std::string desc)
	HealthPotion(int _id = HP_ID, bool _bound = HP_BOUND, int _uses = HP_DEFAULT_USES, 
		std::string desc = "Health Potion");


	~HealthPotion();

	void use(Player*) override;
};

#endif