#include "Connector.h"



Connector::Connector(std::vector<std::string>* prompts) :
	Space('X', prompts)
{
}


Connector::~Connector()
{
}

void Connector::onEnter(Player*)
{
}

void Connector::update()
{
}

bool Connector::onExit(Player*)
{
	return true;
}
