#ifndef SHRINE_HPP
#define SHRINE_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Shrine type room. Inherits from Space.

The shrine is where special items are placed for the player to pick up.
Simple room that cannot spawn entities.

***********************************************************/

#include "Space.h"


class Shrine : public Space
{

public:


	Shrine(std::vector<std::string>* prompts);

	~Shrine();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;


};

#endif