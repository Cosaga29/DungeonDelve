#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Item.h"
#include "Space.h"
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

	Entity(Space* startSpace, int startHealth, int startAttack, std::string name = "Player");

	void drop(int item_id);

	void get(Item* pickup);

	virtual ~Entity();

	virtual void attack(Entity*) = 0;

	virtual bool move(DIRECTION) = 0;

	virtual bool get() = 0;


	

};

#endif