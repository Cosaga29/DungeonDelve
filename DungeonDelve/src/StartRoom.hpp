#ifndef STARTROOM_HPP
#define STARTROOM_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the StartRoom class. The start room class
is a room subclass where the player starts.

The start room prints the guide to the game, along with a map

***********************************************************/

#include "Space.hpp"


class StartRoom : public Space
{


public:

	StartRoom(std::vector<std::string>* prompts);

	~StartRoom();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;
};

#endif
