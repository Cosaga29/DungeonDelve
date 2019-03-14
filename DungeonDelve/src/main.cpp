#include "Game.h"


int main() {


	Menu startMenu;
	startMenu.addPrompt("Play Dungeon Delve");
	startMenu.addPrompt("Exit");

	bool playAgain = true;
	char userChoice;

	while (startMenu.getUserChoice() != startMenu.getExitCode() && playAgain == true) {

		//create a game object
		Game newGame;

		newGame.run();

		clearInputStream();

		userChoice = validateInputYN("Would you like to play again? (y/n)");
		if (userChoice == 'y') {
			playAgain = true;
		}
		else {
			playAgain = false;
		}

	}


	clearInputStream();
	std::cin.get();

	return 0;
}