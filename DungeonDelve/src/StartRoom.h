#ifndef STARTROOM_HPP
#define STARTROOM_HPP


#include "Space.h"


class StartRoom : public Space
{


public:

	StartRoom(std::vector<std::string>* prompts);

	~StartRoom();

	bool onEnter(Player*) override;

	void update(Player*) override;

	bool onExit(Player*) override;
};

#endif
