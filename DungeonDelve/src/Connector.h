#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP


#include "Space.h"
class Connector : public Space
{
public:

	Connector(std::vector<std::string>* prompts);

	~Connector();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;



};

#endif