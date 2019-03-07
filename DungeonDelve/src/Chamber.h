#ifndef CHAMBER_HPP
#define CHAMBER_HPP


#include "Space.h"
class Chamber : public Space
{
public:

	Chamber(std::vector<std::string>* prompts);

	~Chamber();

	void onEnter() override;

	void update() override;

	void onExit() override;


};

#endif