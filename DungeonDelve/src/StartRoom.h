#ifndef STARTROOM_HPP
#define STARTROOM_HPP


#include "Space.h"


class StartRoom : public Space
{


public:

	StartRoom(std::vector<std::string>* prompts);

	~StartRoom();

	void onEnter() override;

	void update() override;

	void onExit() override;
};

#endif
