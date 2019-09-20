/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: Zoo class file. Defines all functions used to run the 
				game and interact with the animal classes.
*********************************************************************/

#include "Zoo.hpp"
#include <cstdlib>
#include <iostream>
#include "Validators.hpp"

using std::cout;
using std::endl;

/*********************************************************************
** Description: Default constructor, sets daycount, starting cash, and 
				array specific variables as well as defining the arrays 
				for each animal
*********************************************************************/
Zoo::Zoo() {
	dayCount = 0;
	cash = 100000;
	dayCash = 0;
	feedCost = 0;
	gameOver = false;
	menuAns = 0;
	pengAdult = false;
	tigAdult = false;
	turtAdult = false;

	pengArrayCap = 10;
	nPenguins = 0;
	pengArray = new Penguin[pengArrayCap];

	tigArrayCap = 10;
	nTigers = 0;
	tigArray = new Tiger[tigArrayCap];

	turtArrayCap = 10;
	nTurtles = 0;
	turtArray = new Turtle[turtArrayCap];
}

/*********************************************************************
** Description: Destructor, frees mem
*********************************************************************/
Zoo::~Zoo() {
	delete[] pengArray;
	delete[] tigArray;
	delete[] turtArray;
}

/*********************************************************************
** Description: Determines the daily random event. The passed in int 
				represents the percent chance of a random event occuring.
				If a randome event is triggered, there is an 1/3 chance for 
				each event to occur after that
*********************************************************************/
void Zoo::randEvent(int chance) {
	int eventChance = ((rand() % 100) + 1);
	int whichEvent = ((rand() % 3) + 1);

	if (chance >= eventChance) {
		if (whichEvent == 1) {
			attnBoom();
		}
		else if (whichEvent == 2) {
			newBaby();
		}
		else if (whichEvent == 3) {
			sickness();
		}
	}
}

/*********************************************************************
** Description: Boom in zoo attendance results in a bonus daily earnings. 
				250-500 extra per tiger.
*********************************************************************/
void Zoo::attnBoom() {
	int boomCash;

	cout << "There has been an boom in today's zoo attendance!" << endl;

	boomCash = ((rand() % 500) + 250);
	boomCash *= nTigers;

	cout << "You got a $" <<  boomCash << " bonus!" << endl;

	dayCash += boomCash;
}

/*********************************************************************
** Description: a animal type is selected randomly, if that type has an 
				animal of age 3 or greater, a new baby is born of that type
*********************************************************************/
void Zoo::newBaby() {	
	int whichAnimal = ((rand() % 3) + 1);										//randomy select animal type

	if (whichAnimal == 1) {
		if ((pengAdult == true) && (nPenguins != 0)) {							//check adult flag
			cout << "One of your penguins had babies!" << endl;

			nPenguins += pengArray[0].getBabies();

			if ((nPenguins + pengArray[0].getBabies() ) >= pengArrayCap) {		//check if number of penguins exceeds cap
				doublePengArray();
			}

		}
	}
	else if (whichAnimal == 2) {
		if ((tigAdult == true) && (nTigers != 0)) {
			cout << "One of your Tigers had a baby!" << endl;

			nTigers += tigArray[0].getBabies();

			if ((nTigers + tigArray[0].getBabies()) >= tigArrayCap) {
				doubleTigArray();
			}
		}
	}
	else if (whichAnimal == 3) {
		if ((turtAdult == true) && (nTurtles != 0)) {
			cout << "One of your Turtles had babies!" << endl;

			nTurtles += turtArray[0].getBabies();

			if ((nTurtles + turtArray[0].getBabies()) >= turtArrayCap) {
				doubleTurtArray();
			}
		}

	}

}

/*********************************************************************
** Description: 1 animal dies of a random type
*********************************************************************/
void Zoo::sickness() {
	int whichAnimal = ((rand() % 3) + 1);										//pick random animal
	
	if (whichAnimal == 1) {
		pengArray[nPenguins - 1].setAge(0);										//reset age
		nPenguins--;															//subtract animal from counter
	}
	else if (whichAnimal == 2) {
		tigArray[nTigers - 1].setAge(0);
		nTigers--;
	}
	else if (whichAnimal == 3) {
		turtArray[nTurtles - 1].setAge(0);
		nTurtles--;
	}

}

/*********************************************************************
** Description: a new animal is purchsed. checks if the array is large enough, 
				then increments the count and subtracts the money required to purchase
*********************************************************************/
void Zoo::buyAnimal(int animalChoice) {
	if (animalChoice == 1) {
		nPenguins++;
		if (nPenguins >= pengArrayCap) {									//check if number of penguins exceeds cap
			doublePengArray();
		}
		cash -= 1000;														//subtract cost from total
		pengArray[nPenguins - 1].setAge(3);									// set age to 3
	}
	else if (animalChoice == 2) {
		nTigers++;
		if (nTigers >= tigArrayCap) {
			doubleTigArray();
		}
		cash -= 10000;
		tigArray[nTigers - 1].setAge(3);
	}
	else if (animalChoice == 3) {
		nTurtles++;
		if (nTurtles >= turtArrayCap) {
			doubleTurtArray();
		}
		cash -= 100;
		turtArray[nTurtles - 1].setAge(3);
	}
}

/*********************************************************************
** Description: New day sequence. See comments for outline
*********************************************************************/
void Zoo::newDay() {
																			//increment days, print days
	dayCount++;
	cout << "Day: " << dayCount << endl;
																			//print cash
	cout << "Bank: $" << cash << endl;
																			//print animal inventory
	printAnimalInventory();
																			//increase age
	ageAll();
																			//feed all animals
	feedAll();
																			//random event
	randEvent(60);
																			//calculate profit
	profitCalc();
																			//prompt to buy an animal
	cout << "Would you like to buy an additional animal? y/n" << endl;
	menuAns = ynValidator();
	if (menuAns == 'y') {

		cout << endl;
		cout << "Which animal would you like to buy?" << endl;
		cout << "1. Penguin for $1000" << endl;
		cout << "2. Tiger for $10,000" << endl;
		cout << "3. Turtle for $100" << endl;
		cout << "4. No new animal" << endl;
																			//user selection
		menuAns = intValidator(1, 4);

		switch (menuAns) {
		case 1:
			buyAnimal(1);
			break;
		case 2:
			buyAnimal(2);
			break;
		case 3:
			buyAnimal(3);
			break;
		case 4:
			break;
		}
	}
	cout << endl << endl << endl << turtArray[0].getReturn() << endl;																		//keep playing?
	cout << "Continue playing?" << endl;
	menuAns = ynValidator();
	cout << endl;
	if (menuAns == 'n') {
		gameOver = true;
	}
																			//check game overflag
	if (cash <= 0) {
		cout << "Out of money! You lose!" << endl;
		gameOver = true;
	}
}

/*********************************************************************
** Description: Ages all active animals in array 
*********************************************************************/
void Zoo::ageAll() {
	for (int i = 0; i < nPenguins; i++) {									//age animals in array
		pengArray[i].setAge(pengArray[i].getAge() + 1);
	}
	for (int i = 0; i < nTigers; i++) {
		tigArray[i].setAge(tigArray[i].getAge() + 1);
	}
	for (int i = 0; i < nTurtles; i++) {
		turtArray[i].setAge(turtArray[i].getAge() + 1);
	}

	isAdult();																//check for adult flags
}

/*********************************************************************
** Description: subtracts the feeding cost for each active animal
*********************************************************************/
void Zoo::feedAll() {
	feedCost = 0;

	feedCost += nPenguins * pengArray[0].getFeedingCost();					//calc cumilative feeding cost
	feedCost += nTigers * tigArray[0].getFeedingCost();
	feedCost += nTurtles * turtArray[0].getFeedingCost();

	cash -= feedCost;														//subtract from bank

	cout << "You spent $" << feedCost << " on feeing your animals." << endl;
}

/*********************************************************************
** Description: Start game sequence see comments for outline
*********************************************************************/
void Zoo::startGame() {
																			//welcome players
	cout << "Hello! Welcome to Zoo Tycoon: Text Adventure!" << endl;
																			//give instructions
	cout << "You are the proud owner of a zoo that houses tigers, penguins, and turtles. Oh my!" << endl;
	cout << "Unfortunately when you were on you vacation in the carribiean your zoo-friends all escaped" << endl;
	cout << "their cages and you need to start over" << endl;
	cout << "Luckily, your zoo-insurance covered the loss, giving you $100,000 to start over." << endl;

																			//prompt player to buy 1 or 2 of each type of animal
	cout << "Let us begin with your first purchases." << endl;
	cout << "There are only 2 of each type of animal avaliable currenso use your funds carefully!" <<endl;
	cout << "You will have the option to buy another new animal after each day." << endl << endl;
																			//buy Penguins, validate
	cout << "How many Penguins at $10,000 each would you like to purchase? Answer with 1 or 2." << endl;
	nPenguins = intValidator(1, 2);
	cout << endl;
	cash -= (nPenguins * pengArray[0].getBuyCost());
																			//buy tigers, validate
	cout << "How many Tigers at $1000 each would you like to purchase? Answer with 1 or 2." << endl;
	nTigers = intValidator(1, 2);
	cout << endl;
	cash -= (nTigers * tigArray[0].getBuyCost());
																			//buy turtles, validate
	cout << "How many Turtles at $100 each would you like to purchase? Answer with 1 or 2." << endl;
	nTurtles = intValidator(1, 2);
	cout << endl;
	cash -= (nTurtles * turtArray[0].getBuyCost());
}
/*********************************************************************
** Description:calculates daily profits, adds profits to bank
*********************************************************************/
void Zoo::profitCalc() {
	dayCash = 0;
	dayCash += pengArray[0].getReturn() * nPenguins;
	dayCash += tigArray[0].getReturn() * nTigers;  
	dayCash += turtArray[0].getReturn() * nTurtles;

	cout << "Your daily earning amounts to: $" << dayCash << endl;
	cash += dayCash;
	cout << "You have $" << cash << " in the bank!" << endl;
}

/*********************************************************************
** Description: Prints number of each animal in zoo
*********************************************************************/
void Zoo::printAnimalInventory() {
	cout << "You curerntly have:" << endl;
	cout << nPenguins << " penguins," << endl;
	cout << nTigers << " tigers," << endl;
	cout << "and " << nTurtles << " turtle in your zoo" << endl;
}

/*********************************************************************
** Description: double sthe size of the penguin array cap, see comments for outline.
*********************************************************************/
void Zoo::doublePengArray() {
																			//double capacity int
	pengArrayCap *= 2;
																			//create a new Array
	Penguin* temp = new Penguin[pengArrayCap];
																			//copy all entries from old array to new array
	for (int i = 0; i < (pengArrayCap / 2); i++) {
		temp[i] = pengArray[i];
	}
																			//delete old array
	delete[] pengArray;	

	pengArray = temp;

}

/*********************************************************************
** Description: double sthe size of the tiger array cap, see comments for outline.
*********************************************************************/
void Zoo::doubleTigArray() {
																			//double capacity int
	tigArrayCap *= 2;
																			//create a new Array
	Tiger* temp = new Tiger[tigArrayCap];
																			//copy all entries from old array to new array
	for (int i = 0; i < (tigArrayCap / 2); i++) {
		temp[i] = tigArray[i];
	}
																			//delete old array
	delete[] tigArray;

	tigArray = temp;
}

/*********************************************************************
** Description: double sthe size of the turtle array cap, see comments for outline.
*********************************************************************/
void Zoo::doubleTurtArray() {
																			//double capacity int
	turtArrayCap *= 2;
																			//create a new Array
	Turtle* temp = new Turtle[turtArrayCap];
																			//copy all entries from old array to new array
	for (int i = 0; i < (turtArrayCap / 2); i++) {
		temp[i] = turtArray[i];
	}
																			//delete old array
	delete[] turtArray;

	turtArray = temp;
}

/*********************************************************************
** Description: Checks the adultflag for each animal and raises it if it 
				finds an amilam age 3 or older
*********************************************************************/
void Zoo::isAdult() {
	pengAdult = false;
	for (int i = 0; i < nPenguins; i++) {
		if (pengArray[i].getAge() >= 3) {
			pengAdult = true;
		}
	}
	pengAdult = false;
	for (int i = 0; i < nTigers; i++) {
		if (tigArray[i].getAge() >= 3) {
			tigAdult = true;
		}
	}
	turtAdult = false;
	for (int i = 0; i < nTurtles; i++) {
		if (turtArray[i].getAge() >= 3) {
			turtAdult = true;
		}
	}
}