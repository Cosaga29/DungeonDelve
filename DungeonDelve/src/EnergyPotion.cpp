/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the EnergyPotion class, inherits from Item.

Defines an item that can be used by the player to restore their energy
pool. The potions have 2 uses that restore 50 energy each, up to 100 energy.

***********************************************************/

#include "EnergyPotion.hpp"
#include "Player.hpp"


/*
Constructor
*/
EnergyPotion::EnergyPotion(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
}

/*Desctructor*/
EnergyPotion::~EnergyPotion()
{
}

/*
Implements the player using the energy potion. Checks to see if the potion has 
any uses, if not the item name changes to update the player that the potion is empty.

If the potion is not empty, restores the players energy and subtracts uses
*/
void EnergyPotion::use(Player* pl)
{
	if (uses <= 0) {	//no uses remain, change items description
		std::cout << "\n\nThe energy potion is empty.. \n" << std::endl;
	}
	else {
		std::cout << "\n\nYou take a sip of the energy potion.\n" << std::endl;
		pl->restoreEnergy(EP_RESTORE);
		--uses;
		
		//check for empty bottle, update description
		if (uses <= 0) {
			description = "Energy Potion [Empty]";
			std::cout << "\n\nThe energy potion is empty.. \n" << std::endl;
		}
	}
}
