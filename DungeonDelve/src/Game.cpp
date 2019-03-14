#include "Game.h"


Game::Game()
{
	//build prompts to be used for game, must be done before map generation
	//shrinePrompts.push_back("Shrine");
	//connectorPrompts.push_back("Connector");


	startRoomPrompts.push_back("Start Room");
	exitPrompts.push_back("Exit Room");
	//chamberPrompts.push_back("Boss Chamber");
	

	//generate room prompts
	connectorPrompts.push_back("A dark, damp hallway. You think you hear something moving, but you're not sure.\n");
	connectorPrompts.push_back("A hallway adorned with a red substance on the walls, it seems to be getting hotter.\n");
	connectorPrompts.push_back("An expansive room with menacing statues along the walls. You start to wonder who built this place.\n");
	connectorPrompts.push_back("A white hallway, you hear the shifting sounds of rock. The rooms seem to be changing.\n");
	connectorPrompts.push_back("Another dark damp hallway, are the rooms changing or are random descriptions being used?\n");
	chamberPrompts.push_back("A huge cavern lies below you. You hear the sounds of shackles dragging accross the floor.\nYou look around and spot a huge demon with a small key at the end of his massive sword (is that a keyblade?)\n");
	shrinePrompts.push_back("This room is unlike the others. It seems to be pushing back the darkness of the surrounding rooms.\nIt seems that this room was made to help you.\n");



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
	bound_player.reset(new Player(map[2][0], 50, 5));
	
}

/*
Game destructor, claim memory allocated for the map
*/
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

	//spawn necessary items
	map[4][0]->_inventory.push_back(std::unique_ptr<Item>(new Shield()));
	map[0][1]->_inventory.push_back(std::unique_ptr<Item>(new BottledRage()));

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
	//std::cout << "Linking rooms. " << std::endl;
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 6; x++) { // for each space, look at that spaces north, east, west south

			//check left
			if (map[y][x] != 0) {
				//std::cout << "Space [" << x << "," << y << "] linked." << std::endl;
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

*/
void Game::run()
{
	int userInput;
	bool userExit = false;

	bound_player->getCurrentSpace()->onEnter(bound_player.get());

	while (!userExit) {

		//print map, room description, enemies in room, items in room
		bound_player->look();

		//display player actions available for the room
		bound_player->actions.display();

		//get input from the user
		userInput = validateInputRange(1, bound_player->getNumOfActions());
		
		//dispatch event to the userChoice function to resolve input event
		userExit = onUserChoice(userInput);

		//check if user wanted to exit
		if (userExit) {
			return;
		}

		//update room - resolve monster attacks, check to see if items that have 0 uses need to be deleted, or delete them automatically on 0 uses
		bound_player->getCurrentSpace()->update(bound_player.get());
		//if any enemies, attack the player


		//check for player death events
		if (checkPlayer()) {
			return;
		}

	}
		
}



/*
Check player health and energy at the end of the game loop
*/
bool Game::checkPlayer() const
{
	//if player energy <= 0 or health <= 0, return true
	if (bound_player->isExhausted() || bound_player->playerDead()) {
		return true;
	}
	else {
		return false;
	}
}



/*
Function to handle user input from the terminal.
Each option is linked to an action that gets executed.

1-4 - move
5	- inventory
6	- attack
7	- get Item
8	- Look 
9	- Exit

*/
bool Game::onUserChoice(int userInput) {
	std::cout << "\n\n" << std::endl;
	if (userInput == bound_player->getNumOfActions()) {
		return true;
	}
	//user gave a move command
	if (userInput >= 1 && userInput <= 4)
	{


		//call room on exit
		if (bound_player->getCurrentSpace()->onExit(bound_player.get())) {
			Space* previousSpace = bound_player->getCurrentSpace();
			bound_player->move((DIRECTION)userInput);

			if (!bound_player->getCurrentSpace()->onEnter(bound_player.get())) {
				std::cout << "\n\nA mysterious force prevents you from going this way" << std::endl;
				bound_player->setCurrentSpace(previousSpace);
			}
		}


	}
	else if (userInput == 5) //user selected inventory
	{
		//open inventory
		Choice inventoryChoice = bound_player->openInvetory();

		if (inventoryChoice.choice == 0 && inventoryChoice.inventory_index == 0)
		{
			//inventory was empty, message was printed in player class, continue
		}
		else //user would like to drop or use item
		{
			//check if use or drop
			if (inventoryChoice.choice == 1) {	//user would like to use an item
				

				//TODO:: IMPLEMENT THESE
				//test what the item is an modify player health/energy respectively
				//std::cout << "You used " << bound_player->_inventory[inventoryChoice.inventory_index - 1]->getDescription();
				bound_player->_inventory[inventoryChoice.inventory_index - 1]->use(bound_player.get());



			}
			else {								//user would like to drop an item
				//check that the item that the user would like to drop is not bound
				if (bound_player->_inventory[inventoryChoice.inventory_index - 1].get()->bound) {
					//cannot drop item, item is bound
					std::cout << "This item clings to you, you cannot drop it. " << std::endl;
				}
				else {
					bound_player->drop(inventoryChoice.inventory_index - 1);
				}
			}
		}
	}
	else if (userInput == 6)	//user selected to attack
	{
		//select which monster to attack in room, 
		Menu attackList;
		attackList.displayMessage("\n\nChoose an enemy to attack:\n");
		for (unsigned i = 0; i < bound_player->getCurrentSpace()->enemiesInRoom.size(); i++) {
			attackList.addPrompt(bound_player->getCurrentSpace()->enemiesInRoom[i]->name);
		}

		if (attackList.getExitCode() != 0) {
			int attackChoice = attackList.getUserChoice();	//perform an attack on the chosen monster
			bound_player->getCurrentSpace()->enemiesInRoom[attackChoice - 1]->defend(bound_player->attack());
		}
		else {
			std::cout << "\n\nNothing to attack.\n" << std::endl;
		}

		//attack the monster


	}
	else if (userInput == 7) 
	{
		//pick up item from current space
		if (bound_player->getCurrentSpace()->_inventory.empty()) 
		{ //check that there is an item to pick up
			std::cout << "No item to pickup. " << std::endl;
		}
		else 
		{
			//check that players inventory isnt full
			if (bound_player->isFull()) 
			{
				std::cout << "No room in pack!" << std::endl;
			}
			else 
			{
				//build menu of items currently in the room
				Menu roomItems;
				for (int i = 0; i < bound_player->getCurrentSpace()->_inventory.size(); i++) {
					roomItems.addPrompt(bound_player->getCurrentSpace()->_inventory[i]->getDescription());
				}

				//get user choice of item they would like to pick up
				roomItems.displayMessage("\n\nSelect item to pickup: ");
				int roomItemChoice = roomItems.getUserChoice();

				//put item in pack
				bound_player->_inventory.push_back(std::unique_ptr<Item>(bound_player->getCurrentSpace()->_inventory[roomItemChoice-1].release()));

				//remove pointer from inventory

				bound_player->getCurrentSpace()->_inventory.erase(bound_player->getCurrentSpace()->_inventory.begin() + (roomItemChoice - 1));

				//first item in room to pick up

				//bound_player->_inventory.push_back(std::unique_ptr<Item>(bound_player->getCurrentSpace()->_inventory.front().release()));

				//remove first position pointer from room inventory
				//bound_player->getCurrentSpace()->_inventory.erase(bound_player->getCurrentSpace()->_inventory.begin());
			}
		}
	}
	else if (userInput == 8) {	//user decided to look
		//do nothing, player will update next step
	}

	return false;
}