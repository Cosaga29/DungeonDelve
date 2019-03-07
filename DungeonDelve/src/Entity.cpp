#include "Entity.h"


Space * Entity::getCurrentSpace() const
{
	return currentSpace;
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

void Entity::get(Item * pickup)
{
	_inventory.push_back(std::unique_ptr<Item>(pickup));
}


Entity::~Entity()
{
}
