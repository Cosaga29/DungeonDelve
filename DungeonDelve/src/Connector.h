#ifndef CONNECTOR_HPP
#define CONNECTOR_HPP


#include "Space.h"
class Connector : public Space
{
public:

	Connector(std::vector<std::string>* prompts);

	~Connector();

	void onEnter() override;

	void onPlayerAction() override;

	void onExit() override;



};

#endif