#ifndef EP_HPP
#define EP_HPP

#include "Item.h"


#define EP_ID			10
#define EP_BOUND		false
#define EP_DEFAULT_USES	2
#define EP_RESTORE		50

class EnergyPotion : public Item
{
public:

	//Item::Item(int _id, bool _bound, int _uses, std::string desc)
	EnergyPotion(int _id = EP_ID, bool _bound = EP_BOUND, int _uses = EP_DEFAULT_USES, 
		std::string desc = "Energy Potion");


	~EnergyPotion();

	void use(Player*) override;
};

#endif