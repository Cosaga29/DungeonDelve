#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Space.h"
#include "Menu.hpp"

class Entity
{
protected:

	Space* currentSpace;
	int health;
	int attack_power;
	std::vector<Item> inventory;

public:

	Space* getCurrentSpace() const;

	Entity(Space* startSpace, int startHealth, int startAttack);

	std::vector<Item>* getContainer();

	virtual ~Entity();

	virtual void attack(Entity*) = 0;

	virtual bool move(DIRECTION) = 0;

	virtual bool get() = 0;


	

};

#endif