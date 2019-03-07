#pragma once
#include "Item.h"

#define KEY_ID				20
#define KEY_BOUND			true
#define KEY_DEFAULT_USES	-1


class Key : public Item
{
public:


	Key(int _id = KEY_ID, bool _bound = KEY_BOUND, int _uses = KEY_DEFAULT_USES, 
		std::string desc = "A black metal key");


	~Key();

	void use(Player*) override;

};

