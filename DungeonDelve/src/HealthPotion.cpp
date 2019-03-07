#include "HealthPotion.h"



HealthPotion::HealthPotion(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
}


HealthPotion::~HealthPotion()
{
}

void HealthPotion::use()
{
}
