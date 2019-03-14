#include "HealthPotion.h"
#include "Player.h"



HealthPotion::HealthPotion(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
}


HealthPotion::~HealthPotion()
{
}


void HealthPotion::use(Player* pl)
{
	if (uses <= 0) {	//no uses remain, change item description
		std::cout << "\n\nThe healing potion is empty.. \n" << std::endl;
	}
	else {
		if (pl->shieldBuff) {	//player has picked up the shield, change the way the player heals
			std::cout << "\n\nYou take a sip of the healing potion, the shield vibrates in response..." << std::endl;
			pl->restoreHP(HP_RESTORE * 3);
		}
		else {
			std::cout << "\n\nYou take a sip of the healing potion.\n" << std::endl;
			pl->restoreHP(HP_RESTORE);
		}
		--uses;

		if (uses <= 0) {
			description = "Healing Potion [Empty]";
			std::cout << "\n\nThe healing potion is empty.. \n" << std::endl;
		}
	}
	
}
