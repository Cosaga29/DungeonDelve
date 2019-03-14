#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP


#define CONNECTOR_PROMPTS 5

#include "Space.h"
class Connector : public Space
{
public:

	Connector(std::vector<std::string>* prompts);

	~Connector();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;

	void getDescription() const override;



};

#endif