#include "Game.h"


int main() {


	Game newGame;

	newGame.printConnections(newGame.map[2][0]);

	newGame.printMap();

	newGame.getUserAction();



	std::cin.get();

	return 0;
}