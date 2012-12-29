/*
 * EnergyBall1.h
 *
 *  Created on: Apr 13, 2012
 *      Author: David Zhang
 */

#ifndef ENERGYBALL1_H_
#define ENERGYBALL1_H_

#include "Item.h"

class EnergyBall1: public Item {
public:
	EnergyBall1(); // level 1 energy ball

	void randomlyHide(); // virtual fn implemented
	int getEnergyLevel() { return 1; };

protected:
	std::string file();
};

#endif /* ENERGYBALL1_H_ */
