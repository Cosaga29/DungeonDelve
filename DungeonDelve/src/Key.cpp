/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Key item. Inherits from the Item class.
The key is used to beat the game and can only be dropped by the game class.

***********************************************************/

#include "Key.h"



Key::Key(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
}


Key::~Key()
{
}

void Key::use(Player*)
{
	std::cout << "It's a key" << std::endl;
}
