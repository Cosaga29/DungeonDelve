#ifndef CHAMBER_HPP
#define CHAMBER_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the chamber space, inherits from Space.
The chamber is used in the dungeondelve to implement a boss room.

Constructor spawns an entity that must be defeated for a key

***********************************************************/

#include "Space.hpp"
class Chamber : public Space
{

	bool keySpawned;

public:

	Chamber(std::vector<std::string>* prompts);

	~Chamber();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;


};

#endif