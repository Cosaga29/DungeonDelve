#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Connector space, inherits from Space.
The connector space is a generic place on the board. Enemies are allowed
to randomly spawn along with items.

Constructor spawns random enemies and items

***********************************************************/

#define CONNECTOR_PROMPTS 5

#include "Space.hpp"
class Connector : public Space
{
private:


public:

	Connector(std::vector<std::string>* prompts);

	~Connector();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;

	void getDescription() const override;



};

#endif