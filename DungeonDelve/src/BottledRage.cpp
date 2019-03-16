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

#include "BottledRage.h"
#include "Player.h"


BottledRage::BottledRage(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
	toggle_state = false;
}


BottledRage::~BottledRage()
{
}

void BottledRage::use(Player* pl)
{
	toggle_state = !toggle_state; //change toggle on to off

	pl->bottleBuff = true;

	if (toggle_state == true) { //item is on
		std::cout << "\n\nYour sword begins to glow with a brilliant white flame." << std::endl;
		pl->setAttack(100);
	}
	else {
		std::cout << "\n\nThe white flame from your sword fades away." << std::endl;
		pl->setAttack(10);
	}
}
