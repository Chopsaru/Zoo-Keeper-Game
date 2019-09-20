/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: Defines validator functions.
*********************************************************************/

#include "Validators.hpp"
#include <iostream>

using std::endl;
using std::cin;
using std::cout;

/*********************************************************************
** Description: Validates cin int values in between two passed in varibles.
*********************************************************************/
int intValidator(int min, int max) {
	bool invalid;
	int input;
	do {
		invalid = false;
		cin >> input;													//get input
		if (cin.fail() || ((input < min) || (input > max))) {			//in range?	
			invalid = true;
			cout << "Input error. Enter a valid number" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (invalid == true);
	return input;
}

/*********************************************************************
** Description: validates 'y' and 'n' responses
*********************************************************************/
char ynValidator() {
	bool invalid;
	char input;
	cin.clear();														//clear keyboard
	cin.ignore(100, '\n');
	do {
		invalid = false;
		cin >> input;													//get input
		if (cin.fail() || ((input != 'y') && (input != 'n'))) {			//y or n?
			invalid = true;
			cout << "Input error. Enter either y or n" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (invalid == true);
	return input;
}
