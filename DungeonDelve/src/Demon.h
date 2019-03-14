#ifndef DEMON_HPP
#define DEMON_HPP


#include "Entity.h"

#define DEMON_START_HEALTH 10
#define DEMON_START_ATTACK 5

class Demon : public Entity
{
public:

	Demon(Space* startSpace, int startHealth = DEMON_START_HEALTH, int startAttack = DEMON_START_ATTACK, std::string name = "Demon");


	~Demon();

	int attack() override;

	void defend(int) override;

	bool move(DIRECTION) override;
};

#endif