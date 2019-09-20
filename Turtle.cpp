/*********************************************************************
** Author: Greg Noetzel
** Date: 7/12/2019
** Description: Turtle class constructor made with pre-defined values.
*********************************************************************/

#include "Turtle.hpp"

Turtle::Turtle() {
	setAge(0);
	setBuyCost(100);
	setReturn(getBuyCost() * 0.05);
	setFeedingCost(.5);
	setBabies(10);

}