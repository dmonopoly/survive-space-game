/*
 * EnergyBall2.h
 *
 *  Created on: Apr 13, 2012
 *      Author: David Zhang
 */

#ifndef ENERGYBALL2_H_
#define ENERGYBALL2_H_

#include "Item.h"

class EnergyBall2: public Item {
public:
	EnergyBall2(); // level 2 energy ball

	void move(); // overriding superclass
	int getEnergyLevel() { return 2; };
	void randomlyHide();

protected:
	std::string file();
};

#endif /* ENERGYBALL2_H_ */
