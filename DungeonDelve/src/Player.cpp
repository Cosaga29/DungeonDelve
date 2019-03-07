#include "Player.h"



Player::Player(Space* startSpace, int startHP, int startAttack) :
	Entity(startSpace, startHP, startAttack)
{


	//build actions menu
	buildActions();

	_inventory.push_back(std::unique_ptr<Item>(new HealthPotion()));

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
	
	//print enemies in room
	currentSpace->getEnemies();

	//print items in room
	currentSpace->getItems();

}

void Player::buildActions()
{
	//actions.clearMenu();
	actions.addPrompt("Move Up");
	actions.addPrompt("Move Down");
	actions.addPrompt("Move Right");
	actions.addPrompt("Move Left");
	actions.addPrompt("Inventory");
	actions.addPrompt("Attack");
	actions.addPrompt("Get Item");
	//actions.addPrompt("Room Actions");
	actions.addPrompt("Exit");

}

int Player::getNumOfActions() const {
	return actions.getExitCode();
}

Choice Player::openInvetory() //print out user inventory and get input based on what the user would like to do
{
	//build inventory
	items.clearMenu();
	for (auto it = _inventory.begin(); it != _inventory.end(); it++) {
		items.addPrompt((*it).get()->getDescription());				//add item description to inventory prompt
	}
	if (_inventory.empty()) {
		std::cout << "Your inventory is empty!" << std::endl;
		return{ 0, 0 };
	}

	items.addPrompt("Exit");

	Choice toReturn;
	toReturn.inventory_index = items.getUserChoice();	//get the item the user wants

	Menu use_drop;										//get action the user wants to do 
	use_drop.addPrompt("Use");		//1 - use
	use_drop.addPrompt("Drop");		//2 - drop

	toReturn.choice = use_drop.getUserChoice();			//return struct with index/action to game class

	return toReturn;
}

void Player::pickUp()
{

	_inventory.push_back(std::unique_ptr<Item>(currentSpace->_inventory.front().release()));
	currentSpace->_inventory.erase(currentSpace->_inventory.begin());

}
