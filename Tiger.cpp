/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: Turtle class constructor made with pre-defined values.
*********************************************************************/

#include "Tiger.hpp"

Tiger::Tiger() {
	setAge(0);
	setBuyCost(10000);
	setReturn(getBuyCost() * 0.2);
	setFeedingCost(5);
	setBabies(1);
}