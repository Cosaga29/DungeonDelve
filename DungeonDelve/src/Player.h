#ifndef PLAYER_HPP
#define PLAYERHPP
#define PLAYER_HPP


#include "Entity.h"
#include "Menu.hpp"

#define MAX_ITEMS		5
#define PLAYER_HP		50
#define PLAYER_ENERGY	100

struct Choice {
	int choice;
	int inventory_index;
};

class Player : public Entity
{
private:

	int energy;

public:

	Menu actions;
	Menu items;
	Menu roomInterations;

	Player(Space* startSpace, int startHP, int startAttack);

	~Player();

	bool shieldBuff = false;

	void attack(Entity*) override;

	bool move(DIRECTION) override;

	//bool get() override;

	void look() const;

	void buildActions();

	int getNumOfActions() const;

	Choice openInvetory();

	void pickUp();
	
	bool isFull();

	void restoreHP(int);

	void restoreEnergy(int);

	void setAttack(int);

};

#endif