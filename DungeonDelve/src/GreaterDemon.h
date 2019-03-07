#ifndef GREATERDEMON_HPP
#define GREATERDEMON_HPP


#include "Entity.h"

#define GDEMON_START_HEALTH 500
#define GDEMON_START_ATTACK 25

class GreaterDemon : public Entity
{
public:
	GreaterDemon(Space* startSpace, int startHealth = GDEMON_START_HEALTH, int startAttack = GDEMON_START_ATTACK, std::string name = "Greater Demon");
	
	~GreaterDemon();

	int attack() override;

	void defend(int) override;

	bool move(DIRECTION) override;
};

#endif