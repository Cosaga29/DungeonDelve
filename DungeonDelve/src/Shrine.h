#ifndef SHRINE_HPP
#define SHRINE_HPP



#include "Space.h"


class Shrine : public Space
{

public:


	Shrine(std::vector<std::string>* prompts);

	~Shrine();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;


};

#endif