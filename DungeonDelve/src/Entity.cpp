/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Implements the Entity class. Defines an object
that is used by the game class to implement NPCs and the Player.

Defines virtual move, drop and check functions.

***********************************************************/


#include "Entity.h"

/*
Return pointer to current space the entity is in. 
*/
Space * Entity::getCurrentSpace() const
{
	return currentSpace;
}

/*
Sets the entity's space to a spot in the game.
*/
void Entity::setCurrentSpace(Space * space)
{
	currentSpace = space;
}

Entity::Entity(Space* startSpace, int startHealth, int startAttack, std::string name) :
	currentSpace(startSpace), health(startHealth), attack_power(startAttack), name(name)
{
}

/*
Function that simulates dropping of an item from the players inventory
*/
void Entity::drop(int inventory_index)
{

	//push the item to be dropped to the current space the entity is in
	currentSpace->_inventory.push_back(std::unique_ptr<Item>(_inventory[inventory_index].release()));
	_inventory.erase(_inventory.begin() + inventory_index);


}

/*
Simulate the entity picking up an item and putting it in their inventory
*/
void Entity::get(Item * pickup)
{
	_inventory.push_back(std::unique_ptr<Item>(pickup));
}

/*
Setter function
*/
void Entity::setHealth(int value)
{
	health = value;
}

/*
Checks if entity is dead by health 
*/
bool Entity::isDead() const
{
	return health <= 0;
}


Entity::~Entity()
{
}
