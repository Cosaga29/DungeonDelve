#ifndef EP_HPP
#define EP_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the EnergyPotion class, inherits from Item.

Defines an item that can be used by the player to restore their energy
pool. The potions have 2 uses that restore 50 energy each, up to 100 energy.

***********************************************************/

#include "Item.hpp"

#define EP_ID			10
#define EP_BOUND		false
#define EP_DEFAULT_USES	2
#define EP_RESTORE		50

class EnergyPotion : public Item
{
public:

	//Item::Item(int _id, bool _bound, int _uses, std::string desc)
	EnergyPotion(int _id = EP_ID, bool _bound = EP_BOUND, int _uses = EP_DEFAULT_USES, 
		std::string desc = "Energy Potion");


	~EnergyPotion();

	void use(Player*) override;
};

#endif