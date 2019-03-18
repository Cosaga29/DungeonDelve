/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the shield item, inherits from Item.

The shield item is used to buff the player to be able to kill
the greater demon.

***********************************************************/

#include "Shield.hpp"
#include "Player.hpp"

/*Constructor*/
Shield::Shield(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
	firstUse = true;
}

/*Desctructor*/
Shield::~Shield()
{
}

/*
Simulates the use of the shield, initially sets the players health to 10 times the current amount.
Sets the players shield buff flag and removes firstUse flag, so the player cannot re-use

On successive uses, a simple description is printed.

*/
void Shield::use(Player* pl)
{
	if (firstUse) {
		std::cout << "\n\nYou hold the shield in a ready positon and suddenly feel much, much stronger.\n" << std::endl;
		pl->setHealth(PLAYER_HP * 10);
		pl->shieldBuff = true;
		firstUse = false;
	}
	else {
		std::cout << "\n\nA crimson shield with black etchings around the rim, it looks new. \n" << std::endl;
	}
}
