#ifndef EXIT_HPP
#define EXIT_HPP


#include "Space.h"

class ExitRoom : public Space
{
public:

	ExitRoom(std::vector<std::string>* prompts);

	~ExitRoom();

	void onEnter() override;

	void update() override;

	void onExit() override;

};


#endif