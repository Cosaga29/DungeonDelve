#include "Shield.h"
#include "Player.h"


Shield::Shield(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
	firstUse = true;
}


Shield::~Shield()
{
}

void Shield::use(Player* pl)
{
	if (firstUse) {
		std::cout << "\n\nYou hold the shield in a ready positon and suddenly feel much, much stronger.\n" << std::endl;
		pl->setHealth(PLAYER_HP * 10);
		pl->shieldBuff = true;
	}
	else {
		std::cout << "\n\nA crimson shield with black etchings around the rim, it looks new. \n" << std::endl;
	}
}
