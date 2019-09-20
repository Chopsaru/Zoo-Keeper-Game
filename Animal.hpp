/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: Header fir Animal.cpp. Base Class for all animals
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {
protected:
	int baseFoodCost;
	int age;
	int buyCost;
	int cashReturn;
	int nBabies;
	int feedingCost;

public:
	Animal();
	//Animal(int newAge, int newcost, int newReturn, int newbabies);
	Animal(int newAge);

	int getAge();
	int getBuyCost();
	int getReturn();
	int getBabies();
	int getFeedingCost();
	void setAge(int);
	void setBuyCost(int);
	void setReturn(int);
	void setBabies(int);
	void setFeedingCost(float multiplyer);
};

#endif
