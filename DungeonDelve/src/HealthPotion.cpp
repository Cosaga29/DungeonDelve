/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the HealthPotion class, inherits from Item.

Defines an item that can be used by the player to restore their health
pool. The potions have 3 uses that restore 20 health each, up to 60 energy.

***********************************************************/

#include "HealthPotion.hpp"
#include "Player.hpp"



HealthPotion::HealthPotion(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
}


HealthPotion::~HealthPotion()
{
}

/*
Implements the player using the health potion. Checks to see if the potion has
any uses, if not the item name changes to update the player that the potion is empty.

If the potion is not empty, restores the players energy and subtracts uses
*/
void HealthPotion::use(Player* pl)
{
	if (uses <= 0) {	//no uses remain, change item description
		std::cout << "\n\nThe healing potion is empty.. \n" << std::endl;
	}
	else {
		if (pl->shieldBuff) {	//player has picked up the shield, change the way the player heals
			std::cout << "\n\nYou take a sip of the healing potion, the shield vibrates in response..." << std::endl;
			pl->restoreHP(HP_RESTORE * 3);
		}
		else {
			std::cout << "\n\nYou take a sip of the healing potion.\n" << std::endl;
			pl->restoreHP(HP_RESTORE);
		}
		--uses;

		if (uses <= 0) {
			description = "Healing Potion [Empty]";
			std::cout << "\n\nThe healing potion is empty.. \n" << std::endl;
		}
	}
	
}
