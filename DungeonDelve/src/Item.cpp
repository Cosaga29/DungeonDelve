#include "Item.h"
#include "Player.h"



Item::Item(int _id, bool _bound, int _uses, std::string desc) :
	item_id(_id), bound(_bound), uses(_uses), description(desc)
{
}

Item::~Item()
{
}

std::string Item::getDescription() const
{
	return description;
}
