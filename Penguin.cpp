/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: Penguin class constructor made with pre-defined values.
*********************************************************************/

#include "Penguin.hpp"

Penguin::Penguin() {
	setAge(0);
	setBuyCost(1000);
	setReturn(getBuyCost() * 0.1);
	setFeedingCost(1);
	setBabies(5);
}