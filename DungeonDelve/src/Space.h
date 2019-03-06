#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include <string>
#include "Item.h"
#include <iostream>

enum SPACE_TYPE { SHRINE, CHAMBER, CONNECTOR, EXIT };

enum DIRECTION { TOP = 1, BOTTOM, RIGHT, LEFT };

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

	std::vector<Item> itemsInRoom;

	void getDescription() const;

	char getMapChar() const;

	Space(char c, std::vector<std::string>*);

	virtual ~Space();

	virtual void onEnter() = 0;
	virtual void onPlayerAction() = 0;
	virtual void onExit() = 0;


};


bool transferItem(std::vector<Item>* source, std::vector<Item>* destination);

#endif