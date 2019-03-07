#ifndef HP_HPP
#define HP_HPP

#include "Item.h"


#define HP_ID			15
#define HP_BOUND		false
#define DEFAULT_USES	3
#define EP_RESTORE		15


class HealthPotion : public Item
{
public:

	//Item::Item(int _id, bool _bound, int _uses, std::string desc)
	HealthPotion(int _id = HP_ID, bool _bound = HP_BOUND, int _uses = DEFAULT_USES, 
		std::string desc = "Health Potion");


	~HealthPotion();

	void use() override;
};

#endif