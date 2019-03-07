#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include <string>
#include <memory>
#include "Item.h"
#include <iostream>
#include "HealthPotion.h"
#include "EnergyPotion.h"
#include "BottledRage.h"

typedef std::vector<std::unique_ptr<Item> > Inventory;

enum SPACE_TYPE { SHRINE, CHAMBER, CONNECTOR, EXIT };

enum DIRECTION { TOP = 1, BOTTOM, RIGHT, LEFT };

class Entity;

class Item;

class Player;

class Space
{


protected:

	const char mapChar;


public:

	Space* top;
	Space* bottom;
	Space* right;
	Space* left;

	const std::vector<std::string>* prompts;	//container pointing to the available prompts for the room type- init in subclass contructor

	Inventory _inventory;

	std::vector<std::unique_ptr<Entity >> enemiesInRoom;

	void getDescription() const;
	void getItems() const;
	void getEnemies() const;

	void removeDeadEnemies();

	char getMapChar() const;

	Space(char c, std::vector<std::string>*);

	virtual ~Space();

	virtual bool onEnter(Player*) = 0;
	virtual void update(Player*) = 0;
	virtual bool onExit(Player*) = 0;


};


#endif