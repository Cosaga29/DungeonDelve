#ifndef PLAYER_HPP
#define PLAYERHPP
#define PLAYER_HPP


#include "Entity.h"
#include "Menu.hpp"

#define MAX_ITEMS 5


class Player : public Entity
{

public:

	Menu actions;

	Player(Space* startSpace, int startHP, int startAttack);

	~Player();

	void attack(Entity*) override;

	bool move(DIRECTION) override;

	bool get() override;

	void look() const;

	void buildActions();

	int getNumOfActions() const;

};

#endif