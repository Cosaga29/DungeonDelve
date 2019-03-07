#ifndef BR_HPP
#define BR_HPP

#include "Item.h"



#define BR_ID			5
#define BR_BOUND		true
#define DEFAULT_USES	-1


class BottledRage : public Item
{
public:

	//Item::Item(int _id, bool _bound, int _uses, std::string desc)
	BottledRage(int _id = BR_ID, bool _bound = BR_BOUND, int _uses = DEFAULT_USES,
		std::string desc = "Bottled Rage");


	~BottledRage();

	void use() override;



};

#endif
