#include "EnergyPotion.h"
#include "Player.h"



EnergyPotion::EnergyPotion(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
}


EnergyPotion::~EnergyPotion()
{
}

void EnergyPotion::use(Player* pl)
{
	if (uses <= 0) {	//no uses remain, change items description
		std::cout << "\n\nThe energy potion is empty.. \n" << std::endl;
	}
	else {
		std::cout << "\n\nYou take a sip of the energy potion.\n" << std::endl;
		pl->restoreEnergy(EP_RESTORE);
		--uses;
		
		//check for empty bottle, update description
		if (uses <= 0) {
			description = "Energy Potion [Empty]";
			std::cout << "\n\nThe energy potion is empty.. \n" << std::endl;
		}
	}
}
