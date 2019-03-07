#ifndef HP_HPP
#define HP_HPP

#include "Item.h"


#define HP_ID			15
#define HP_BOUND		false
#define HP_DEFAULT_USES	3
#define HP_RESTORE		15


class HealthPotion : public Item
{
public:

	//Item::Item(int _id, bool _bound, int _uses, std::string desc)
	HealthPotion(int _id = HP_ID, bool _bound = HP_BOUND, int _uses = HP_DEFAULT_USES, 
		std::string desc = "Health Potion");


	~HealthPotion();

	void use(Player*) override;
};

#endif