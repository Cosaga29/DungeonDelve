#include "EnergyPotion.h"



EnergyPotion::EnergyPotion(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
}


EnergyPotion::~EnergyPotion()
{
}

void EnergyPotion::use()
{
}
