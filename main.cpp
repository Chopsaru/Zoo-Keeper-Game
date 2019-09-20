/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: main function. initialises the rand seed, initializes 
				zoo class, starts the game, then loops the new day 
				function until the game over flag is raised.
*********************************************************************/

#include "Animal.hpp"
#include "Zoo.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;

int main() {
	srand(time(0));
	Zoo zoo;

	zoo.startGame();

	while (zoo.gameOver == false) {
		zoo.newDay();
	}

	return 0;
}