#include "Key.h"



Key::Key(int _id, bool _bound, int _uses, std::string desc) :
	Item(_id, _bound, _uses, desc)
{
}


Key::~Key()
{
}

void Key::use(Player*)
{
	std::cout << "It's a key" << std::endl;
}
