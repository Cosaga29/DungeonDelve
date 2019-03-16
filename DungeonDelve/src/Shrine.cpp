/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Shrine type room. Inherits from Space.

The shrine is where special items are placed for the player to pick up.
Simple room that cannot spawn entities.

***********************************************************/

#include "Shrine.h"


/*Constructor*/
Shrine::Shrine(std::vector<std::string>* prompts) :
	Space('S', prompts)
{
}

/*Destructor*/
Shrine::~Shrine()
{
}

/*Not used by the shrine class*/
bool Shrine::onEnter(Player*)
{
	return true;
}


/*Not used by the shrine class*/
void Shrine::update(Player*)
{
}


/*Not used by the shrine class*/
bool Shrine::onExit(Player*)
{
	return true;
}
