#ifndef ENTITY_HPP
#define ENTITY_HPP

/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Entity class. Defines an object
that is used by the game class to implement NPCs and the Player.

Defines virtual move, drop and check functions.

***********************************************************/

#include "Item.hpp"
#include "Space.hpp"
#include "Menu.hpp"

class Entity
{

protected:

	Space* currentSpace;
	int health;
	int attack_power;

public:

	std::string name;

	Inventory _inventory;

	Space* getCurrentSpace() const;

	void setCurrentSpace(Space*);

	Entity(Space* startSpace, int startHealth, int startAttack, std::string name = "Player");

	void drop(int inventory_index);

	void get(Item* pickup);

	void setHealth(int);

	bool isDead() const;

	virtual ~Entity();

	virtual int attack() = 0;

	virtual void defend(int) = 0;

	virtual bool move(DIRECTION) = 0;

	//virtual bool get() = 0;


	

};

#endif