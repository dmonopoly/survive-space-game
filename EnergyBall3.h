/*
 * EnergyBall3.h
 *
 *  Created on: Apr 13, 2012
 *      Author: David Zhang
 */

#ifndef ENERGYBALL3_H_
#define ENERGYBALL3_H_

#include "Item.h"

class EnergyBall3: public Item {
public:
	EnergyBall3(); // level 3 energy ball

	void move(); // overriding
	int getEnergyLevel() { return 3; };
	void randomlyHide(); // so the level 3 energy ball rarely appears

protected:
	std::string file();
};

#endif /* ENERGYBALL3_H_ */
