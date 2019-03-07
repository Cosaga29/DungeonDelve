#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "Chamber.h"
#include "Connector.h"
#include "Entity.h"
#include "Item.h"
#include "Player.h"
#include "Shrine.h"
#include "Space.h"
#include "StartRoom.h"
#include "ExitRoom.h"
#include <memory>
#include "Shield.h"
#include "HealthPotion.h"
#include "EnergyPotion.h"
#include "Key.h"
#include "BottledRage.h"
#include "Demon.h"
#include "GreaterDemon.h"

#define MAP_WIDTH	6
#define MAP_HEIGHT	7

using std::unique_ptr;

class Game
{
private:

public:

	bool onUserChoice(int choice);

	Game();
	
	~Game();

	//map is row-major order map[y][x]

	std::vector<Space* > rows;
	std::vector<std::vector<Space* >> map;
	std::unique_ptr<Player> bound_player;

	//define containers that rooms will pool from when the user moves between rooms
	std::vector<std::string> shrinePrompts;
	std::vector<std::string> connectorPrompts;
	std::vector<std::string> startRoomPrompts;
	std::vector<std::string> chamberPrompts;
	std::vector<std::string> exitPrompts;

	void genMap();

	bool validPos(int x, int y);

	void linkRooms();

	void linkRoomsLR(Space*, Space*);

	void linkRoomsTB(Space*, Space*);

	void printConnections(Space* space);

	void printMap() const;

	void run();




};




#endif