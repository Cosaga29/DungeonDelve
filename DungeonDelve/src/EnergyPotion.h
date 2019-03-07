#ifndef EP_HPP
#define EP_HPP

#include "Item.h"


#define EP_ID			10
#define EP_BOUND		false
#define DEFAULT_USES	3
#define EP_RESTORE		10

class EnergyPotion : public Item
{
public:

	//Item::Item(int _id, bool _bound, int _uses, std::string desc)
	EnergyPotion(int _id = EP_ID, bool _bound = EP_BOUND, int _uses = DEFAULT_USES, 
		std::string desc = "A yellow elixer, you think that you hear a faint buzzing sound from within... ");


	~EnergyPotion();

	void use() override;
};

#endif