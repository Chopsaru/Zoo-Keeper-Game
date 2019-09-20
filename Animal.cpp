/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: base class file for the animal class. inclues default constructor
				as well as unique constructor for new animal. Also defines 
				virtual getters and setters for child classes.
*********************************************************************/

#include "Animal.hpp"

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Animal::Animal() {
	setAge(0);
	baseFoodCost = 10;
}

/*********************************************************************
** Description: Constructor for adding new animal with a non-zero age.
*********************************************************************/
Animal::Animal(int adultAge) {
	setAge(adultAge);
}


/*********************************************************************
** Description: Constructor for user defined animal
*********************************************************************
Animal::Animal(int newAge, int newCost, int newReturn, int newBabies) {
	setAge(newAge);
	setBuyCost(newCost);
	setReturn(newReturn);
	setBabies(newBabies);
}*/

//getters
int Animal::getAge() {
	return age;
}

int Animal::getBuyCost() {
	return buyCost;
}

int Animal::getReturn() {
	return cashReturn;
}

int Animal::getBabies() {
	return nBabies;
}

int Animal::getFeedingCost() {
	return feedingCost;
}

//setters
void Animal::setAge(int ageIn) {
	age = ageIn;
}

void Animal::setBuyCost(int costIn) {
	buyCost = costIn;
}

void Animal::setReturn(int returnIn) {
	cashReturn = returnIn;
}

void Animal::setBabies(int babiesIn) {
	nBabies = babiesIn;
}

/*********************************************************************
** Description: calculates the feeding cost based on a passed in multipier
*********************************************************************/
void Animal::setFeedingCost(float multiplyer) {
	feedingCost = (baseFoodCost * multiplyer);
}