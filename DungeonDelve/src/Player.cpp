#include "Player.h"



Player::Player(Space* startSpace, int startHP, int startAttack) :
	Entity(startSpace, startHP, startAttack)
{
	//build actions menu
	buildActions();
}


Player::~Player()
{
}

void Player::attack(Entity *)
{
}

/*
Function to move the player and update the players current position
*/
bool Player::move(DIRECTION dir)
{
	switch (dir) {
	case TOP:
		if (currentSpace->top != 0) {
			currentSpace = currentSpace->top;
			return true;
		}
		else {
			std::cout << "I cannot move that direction!" << std::endl;
			return false;
		}
		break;

	case BOTTOM:
		if (currentSpace->bottom != 0) {
			currentSpace = currentSpace->bottom;
			return true;
		}
		else {
			std::cout << "I cannot move that direction!" << std::endl;
			return false;
		}
		break;

	case RIGHT:
		if (currentSpace->right != 0) {
			currentSpace = currentSpace->right;
			return true;
		}
		else {
			std::cout << "I cannot move that direction!" << std::endl;
			return false;
		}
		break;

	case LEFT:
		if (currentSpace->left != 0) {
			currentSpace = currentSpace->left;
			return true;
		}
		else {
			std::cout << "I cannot move that direction!" << std::endl;
			return false;
		}
		break;
	}

	return false;
}

bool Player::get()
{
	return true;
}

/*
Function to print what the player can currently see


*/
void Player::look() const
{
	//print top line of map
	std::cout << ' ';
	std::cout << ((currentSpace->top != 0) ? "|" : " ");
	std::cout << ' ' << "\n";

	//print middle line of map
	std::cout << ((currentSpace->left != 0) ? "-" : " ");
	std::cout << 'P';
	std::cout << ((currentSpace->right != 0) ? "-" : " ") << "\n";

	//print bottom line of map
	std::cout << ' ';
	std::cout << ((currentSpace->bottom != 0) ? "|" : " ");
	std::cout << ' ' << "\n" << std::endl;

	//print room description
	currentSpace->getDescription();

}

void Player::buildActions()
{
	actions.clearMenu();
	actions.addPrompt("Move Up");
	actions.addPrompt("Move Down");
	actions.addPrompt("Move Right");
	actions.addPrompt("Move Left");
	actions.addPrompt("Exit");

}

int Player::getNumOfActions() const {
	return actions.getExitCode();
}
