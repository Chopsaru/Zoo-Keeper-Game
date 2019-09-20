/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: Header fir Zoo.cpp. Contains the class arrays for each animal type 
				and the majority of functions to run the game 
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"

class Zoo {
private:
	int dayCount;
	int dayCash;
	int cash;
	char menuAns;
	int feedCost;

	Penguin* pengArray;
	int nPenguins;
	int	pengArrayCap;
	bool pengAdult;

	Tiger* tigArray;
	int nTigers;
	int tigArrayCap;
	bool tigAdult;

	Turtle* turtArray;
	int nTurtles;
	int  turtArrayCap;
	bool turtAdult;

public:
	bool gameOver;

	Zoo();
	~Zoo();

	void randEvent(int chance);
	void attnBoom();
	void newBaby();
	void sickness();

	void buyAnimal(int animalChoice);
	void newDay();
	void ageAll();
	void feedAll();
	void startGame();
	void profitCalc();
	void doublePengArray();
	void doubleTigArray();
	void doubleTurtArray();
	void printAnimalInventory();
	void isAdult();

};

#endif