#include "Item.h"



Item::Item()
{
}


Item::~Item()
{
}

int Item::getID() const
{
	return item_id;
}

std::string Item::getDescription() const
{
	return description;
}
