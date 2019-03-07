#ifndef SHIELD_HPP
#define SHIELD_HPP

#include "Item.h"

#define SHIELD_ID			25
#define SHIELD_BOUND		true
#define SHIELD_DEFAULT_USES	-1


class Shield : public Item
{
public:

	bool firstUse;

	Shield(int _id = SHIELD_ID, bool _bound = SHIELD_BOUND, int _uses = SHIELD_DEFAULT_USES,
		std::string desc = "A crimson red shield");

	~Shield();

	virtual void use(Player*);
};

#endif
