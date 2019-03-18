/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: Main function fo DungeonDelve.

Creates a starting menu and runs the game. When the player exits
the player can choose to play agian.

***********************************************************/

#include "Game.hpp"

/*
Main function, creates game object and handles playing and replaying the game
*/
int main() {

	//create start menu
	Menu startMenu;
	startMenu.addPrompt("Play Dungeon Delve");
	startMenu.addPrompt("Exit");

	bool playAgain = true;
	char userChoice;

	while (startMenu.getUserChoice() != startMenu.getExitCode() && playAgain == true) {

		//create a game object
		Game newGame;

		//run the game loop
		newGame.run();

		clearInputStream();

		//prompt player to play again
		userChoice = validateInputYN("Would you like to play again? (y/n)");
		if (userChoice == 'y') {
			playAgain = true;
		}
		else {
			playAgain = false;
		}

	}


	//clearInputStream();
	//std::cin.get();

	return 0;
}