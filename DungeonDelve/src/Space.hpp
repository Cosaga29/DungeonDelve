#ifndef SPACE_HPP
#define SPACE_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Space class. The space class
is a superclass that is used by the game glass to model locations
the player can visit.

Each space two contains, one for entities in the room and one
for items in the room.

***********************************************************/

#include <vector>
#include <string>
#include <memory>
#include <random>
#include "Item.hpp"
#include <iostream>
#include "HealthPotion.hpp"
#include "EnergyPotion.hpp"
#include "BottledRage.hpp"

typedef std::vector<std::unique_ptr<Item> > Inventory;

enum SPACE_TYPE { SHRINE, CHAMBER, CONNECTOR, EXIT };

enum DIRECTION { TOP = 1, BOTTOM, RIGHT, LEFT };

class Entity;

class Item;

class Player;

class Space
{


protected:

	const char mapChar;


public:

	Space* top;
	Space* bottom;
	Space* right;
	Space* left;

	const std::vector<std::string>* prompts;	//container pointing to the available prompts for the room type- init in subclass contructor

	Inventory _inventory;

	std::vector<std::unique_ptr<Entity >> enemiesInRoom;

	virtual void getDescription() const;
	void getItems() const;
	void getEnemies() const;

	void removeDeadEnemies();

	char getMapChar() const;

	Space(char c, std::vector<std::string>*);

	virtual ~Space();

	virtual bool onEnter(Player*) = 0;
	virtual void update(Player*) = 0;
	virtual bool onExit(Player*) = 0;


};


#endif