/**********************************************************
Author: Martin Edmunds
Email: edmundsm@oregonstate.edu
Class: CS 162-400
Date: 03/16/19
Description: implements the player glass, inherits from entity.

Defines movement, energy and health, look commands and inventory management.

***********************************************************/

#include "Player.h"


/*
Build the starting action menu, should not change throughout the game.
Sets player energy
*/
Player::Player(Space* startSpace, int startHP, int startAttack) :
	Entity(startSpace, startHP, startAttack)
{


	//build actions menu
	buildActions();
	energy = 100;
	

}

/*Destructor*/
Player::~Player()
{
}

/*Simulates an attack on an object*/
int Player::attack()
{
	return attack_power;
}

/*Simulates a defense from damage.

checks to see if the player has the shield buff, if they do the player
takes half damage.

*/
void Player::defend(int raw_damage)
{
	int damage = raw_damage;
	if (shieldBuff) {			//if the player has the shield, they take half damage (its op)
		damage /= 2;
		std::cout << "\n\nYou took " << damage << " damage! (" << damage << " blocked)" << std::endl;
	}
	else {
		std::cout << "\n\nYou took " << damage << " damage!" << std::endl;
	}
	health -= damage;
}

/*
Function to move the player and update the players current position
*/
bool Player::move(DIRECTION dir)
{
	switch (dir) {
	case TOP:		//player wants to move up
		if (currentSpace->top != 0) {		//if space is good, move and drain energy
			energy -= ENERGY_DRAIN;
			currentSpace = currentSpace->top;
			return true;
		}
		else {
			std::cout << "I cannot move that direction!" << std::endl;
			return false;
		}
		break;

	case BOTTOM:	//player wants to move down
		if (currentSpace->bottom != 0) {	//if space is good, move and drain energy
			energy -= ENERGY_DRAIN;
			currentSpace = currentSpace->bottom;
			return true;
		}
		else {
			std::cout << "I cannot move that direction!" << std::endl;
			return false;
		}
		break;

	case RIGHT:		//player wants to move right
		if (currentSpace->right != 0) {		//if space is good, move and drain energy
			energy -= ENERGY_DRAIN;
			currentSpace = currentSpace->right;
			return true;
		}
		else {
			std::cout << "I cannot move that direction!" << std::endl;
			return false;
		}
		break;

	case LEFT:		//player wants to move left
		if (currentSpace->left != 0) {		//if space is good, move and drain energy
			energy -= ENERGY_DRAIN;
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

/*
Function to print what the player can currently see
*/
void Player::look() const
{
	//print top line of map
	std::cout << "\n[Local Map]\t\t\t" << "[Player Health: " << health << "]" << "\t\t\t [Player Energy: " << energy << "]\n\n";
	std::cout << ' ';
	std::cout << ((currentSpace->top != 0) ? " |" : " \n");
	std::cout << '\n' << "\n";

	//print middle line of map
	std::cout << ((currentSpace->left != 0) ? "- " : "  ");
	std::cout << 'P';
	std::cout << ((currentSpace->right != 0) ? " -" : "  ") << "\n";

	//print bottom line of map
	std::cout << '\n';
	std::cout << ((currentSpace->bottom != 0) ? "  |\n" : "  \n");
	std::cout << ' ' << std::endl;

	//print players health/energy
	//std::cout << "[Player Health: " << health << "]\n";
	//std::cout << "[Player Energy: " << energy << "]\n" << std::endl;

	//print room description
	currentSpace->getDescription();
	
	//print enemies in room
	currentSpace->getEnemies();

	//print items in room
	currentSpace->getItems();

}

/*
Helper function to add all prompts to the player action menu
*/
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
	actions.addPrompt("Look");
	actions.addPrompt("Exit");

}

/*
returns the total number of prompts in the actions menu
*/
int Player::getNumOfActions() const {
	return actions.getExitCode();
}

/*
Simulates the player opening their inventory.
Builds a dynamic menu every time the player calls this function.

The inventory function uses the Choice data structure, which is a convienient way to transfer information
from the game class to the player.
*/
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

	if (toReturn.inventory_index == items.getExitCode()) {
		return { 0, 0 };
	}
	Menu use_drop;										//get action the user wants to do 
	use_drop.addPrompt("Use");		//1 - use
	use_drop.addPrompt("Drop");		//2 - drop

	toReturn.choice = use_drop.getUserChoice();			//return struct with index/action to game class

	return toReturn;
}

/*
Function to simulate picking up an item from the group andplacing it into the player's inventory.
*/
void Player::pickUp()
{
	//push an item into the players inventory from the first spot in the current spaces inventory
	_inventory.push_back(std::unique_ptr<Item>(currentSpace->_inventory.front().release()));

	//erase the pointer to the item in the space, since item is not handled by player
	currentSpace->_inventory.erase(currentSpace->_inventory.begin());

}

/*
Checks that the players inventory isnt full
*/
bool Player::isFull()
{
	return _inventory.size() >= MAX_ITEMS;
}


/*
Function to restore some amount of health to the player.
*/
void Player::restoreHP(int amount)
{
	health += amount;
	//check if player has picked up shield
	if (shieldBuff) {	//player has picked up shield, heal up to 500
		//restore up to max health
		if (health > PLAYER_HP * 10) {
			health = PLAYER_HP * 10;
		}
	}
	else {
		//player hasnt picked up shield, heal up to 50
		if (health > PLAYER_HP) {
			health = PLAYER_HP;
		}
	}

}

/*
Function to restore some amount of energy to the player
*/
void Player::restoreEnergy(int value)
{
	energy += value;
	if (energy > PLAYER_ENERGY) {
		energy = PLAYER_ENERGY;
	}
}

/*
Setter function for attack
*/
void Player::setAttack(int value)
{
	attack_power = value;
}

/*
Checks if the player ran out of energy, if so, then the game will end
*/
bool Player::isExhausted() const
{
	if (this->energy <= 0) {
		std::cout << "You have ran out of energy. Game over." << std::endl;
		return true;
	}

	return false;
}

/*
Checks if hte player ran out of health, if so, then the game will end
*/
bool Player::playerDead() const
{
	if (health <= 0) {
		std::cout << "You have ran out of health. Game over." << std::endl;
		return true;
	}
	return false;
}
