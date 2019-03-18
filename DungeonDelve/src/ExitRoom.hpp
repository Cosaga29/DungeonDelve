#ifndef EXIT_HPP
#define EXIT_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the exitroom. The exitRoom is the final room
for the player to enter. The room checks to make sure the player
has the key on entry. If the player doesnt have the key, it sets
the player's position to the previous room.

Player must kill greater dmeon to spawn the key

***********************************************************/

#include "Space.hpp"

class ExitRoom : public Space
{
public:

	ExitRoom(std::vector<std::string>* prompts);

	~ExitRoom();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;

};


#endif