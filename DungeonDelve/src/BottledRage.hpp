#ifndef BR_HPP
#define BR_HPP

#include "Item.hpp"

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implementation for item used in DungeonDelve.
Implements a toggle-equip item that is used to power up the player.
The item has direct access to the player and can change the players
attack value directly. Inherits from Item

***********************************************************/



#define BR_ID			5
#define BR_BOUND		true
#define BR_DEFAULT_USES	-1


class BottledRage : public Item
{
private:
	bool toggle_state;

public:

	//Item::Item(int _id, bool _bound, int _uses, std::string desc)
	BottledRage(int _id = BR_ID, bool _bound = BR_BOUND, int _uses = BR_DEFAULT_USES,
		std::string desc = "Bottled Rage");


	~BottledRage();

	void use(Player*) override;



};

#endif
