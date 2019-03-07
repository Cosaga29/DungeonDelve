#ifndef SHRINE_HPP
#define SHRINE_HPP



#include "Space.h"


class Shrine : public Space
{

public:


	Shrine(std::vector<std::string>* prompts);

	~Shrine();

	void onEnter() override;

	void update() override;

	void onExit() override;


};

#endif