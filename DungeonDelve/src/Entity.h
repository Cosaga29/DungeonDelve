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