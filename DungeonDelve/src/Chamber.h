#ifndef CHAMBER_HPP
#define CHAMBER_HPP


#include "Space.h"
class Chamber : public Space
{

	bool keySpawned;

public:

	Chamber(std::vector<std::string>* prompts);

	~Chamber();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;


};

#endif