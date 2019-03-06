#include "Game.h"



Game::Game()
{
	//build prompts to be used for game, must be done before map generation
	shrinePrompts.push_back("Shrine");
	connectorPrompts.push_back("Connector");
	startRoomPrompts.push_back("Start Room");
	exitPrompts.push_back("Exit Room");
	chamberPrompts.push_back("Boss Chamber");


	//loop through map array, setting all Space pointers to null
	for (int i = 0; i < MAP_HEIGHT; i++) {
		map.push_back(std::vector<Space*>());
		for (int j = 0; j < MAP_WIDTH; j++) {
			map.back().push_back(0);
		}
	}

	//generate the playable map, set player starting location
	genMap();

	//create player and set starting location
	bound_player.reset(new Player(map[2][0], 100, 5));
	
}


Game::~Game()
{
	for (int i = 0; i < 7; i++) { //for each row
		for (int j = 0; j < 6; j++) { //for each col in row
			if (map[i][j] != 0) {
				delete map[i][j];
			}
		}
	}
}

/*
Function to generate the map for the game
*/
void Game::genMap()
{
	//build map locations setting each space to a certain selection of prompts they are able to print
	map[0][1] = new Shrine(&shrinePrompts);
	map[0][2] = new Connector(&connectorPrompts);
	map[1][2] = new Connector(&connectorPrompts);
	map[1][3] = new Connector(&connectorPrompts);
	map[1][4] = new Connector(&connectorPrompts);
	map[2][0] = new StartRoom(&startRoomPrompts);
	map[2][1] = new Connector(&connectorPrompts);
	map[2][2] = new Connector(&connectorPrompts);
	map[2][4] = new Connector(&connectorPrompts);
	map[3][2] = new Connector(&connectorPrompts);
	map[3][4] = new Connector(&connectorPrompts);
	map[3][5] = new ExitRoom(&exitPrompts);
	map[4][0] = new Shrine(&shrinePrompts);
	map[4][1] = new Connector(&connectorPrompts);
	map[4][2] = new Connector(&connectorPrompts);
	map[5][2] = new Connector(&connectorPrompts);
	map[6][2] = new Connector(&connectorPrompts);
	map[6][3] = new Connector(&connectorPrompts);
	map[6][4] = new Chamber(&chamberPrompts);

	linkRooms();

}

bool Game::validPos(int x, int y) {
	if (x >= 0 && x < MAP_WIDTH) {
		if (y >= 0 && y < MAP_HEIGHT) {
			return true;
		}
	}
	return false;
}

/*
Function that loops through map and attempts to bind all rooms in space
*/
void Game::linkRooms()
{
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 6; x++) { // for each space, look at that spaces north, east, west south

			//check left
			if (map[y][x] != 0) {
				std::cout << "Space [" << x << "," << y << "] linked." << std::endl;
				if (validPos(x - 1, y)) {
					if (map[y][x - 1] != 0) {
						//std::cout << "attempty to link left" << std::endl;
						linkRoomsLR(map[y][x - 1], map[y][x]);
					}
				}
				//check right
				if (validPos(x + 1, y)) {
					if (map[y][x + 1] != 0) {
						//std::cout << "attempty to link right" << std::endl;
						linkRoomsLR(map[y][x], map[y][x + 1]);
					}
				}
				//check top
				if (validPos(x, y - 1)) {
					if (map[y - 1][x] != 0) {
						//std::cout << "attempty to link top" << std::endl;
						linkRoomsTB(map[y - 1][x], map[y][x]);
					}
				}
				//check bottom
				if (validPos(x, y + 1)) {
					if (map[y + 1][x] != 0) {
						//std::cout << "attempty to link bot" << std::endl;
						linkRoomsTB(map[y][x], map[y + 1][x]);
					}
				}
			}
		}
	}
}

/*
Function to link two rooms in left-right positions
*/
void Game::linkRoomsLR(Space* left, Space* right)
{
	left->right = right;
	right->left = left;
}

/*
Function to link two rooms in top-bottom positions
*/
void Game::linkRoomsTB(Space* top, Space* bottom)
{
	top->bottom = bottom;
	bottom->top = top;
}

/*
Debug function to print room connections to std::out
*/
void Game::printConnections(Space * space)
{

	std::cout << "Space: " << space << std::endl;

	std::cout << "\tTop:  " << space->top << " | " << "Bottom: " << space->bottom << std::endl;
	std::cout << "\tRight:" << space->right << " | " << "Left:  " << space->left << "\n\n" << std::endl;

}

void Game::printMap() const
{

	std::cout << "MAP: " << std::endl;
	std::string topBoarder = "----------------\n";

	std::cout << topBoarder;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		std::cout << "| ";
		for (int j = 0; j < MAP_WIDTH; j++) {		//for each space in map

			if (map[i][j] != 0) { 
				std::cout << map[i][j]->getMapChar(); 
			}

			else { 
				std::cout << ' '; 
			}
			std::cout << " ";
		}
		std::cout << " |";
		std::cout << "\n";
	}
	std::cout << topBoarder << "\n";

	std::cout << "P - Starting location\n";
	std::cout << "S - Shrine location\n";
	std::cout << "C - Chamber location\n";
	std::cout << "E - Exit";

	std::cout << "\n\n" << std::endl;


}

/*
GAME-LOOP


gets a prompt from the user, validates it and executes the action

TODO: WORK ON THIS
*/
void Game::getUserAction()
{
	int userInput;

	while (1) {
		bound_player.get()->look();
		bound_player.get()->actions.display();
		userInput = validateInputRange(1, bound_player.get()->getNumOfActions());

		if (userInput >= 1 && userInput <= 4) { //user gave a move command
			bound_player.get()->move((DIRECTION)userInput);
		}
		else {
			break;
		}
	}



}


/*
Helper function to transfer items from an entity to the room that entity is in
*/
bool Game::transferItem(Entity* entity, Item& item)
{
	//check that entity has the item to transfer : IMPLEMENT
	

	//item not found
	return false;
}

