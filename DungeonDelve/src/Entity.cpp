#include "Entity.h"


Space * Entity::getCurrentSpace() const
{
	return currentSpace;
}

Entity::Entity(Space* startSpace, int startHealth, int startAttack) :
	currentSpace(startSpace), health(startHealth), attack_power(startAttack)
{
}

std::vector<Item>* Entity::getContainer(){
	return &inventory;
}


Entity::~Entity()
{
}