#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>

class Player;

class Item
{

public:

	int item_id;
	bool bound;
	int uses;
	std::string description;

	Item(int _id, bool _bound, int _uses, std::string desc);

	virtual ~Item();

	virtual void use(Player*) = 0;

	std::string getDescription() const;
	

};

#endif