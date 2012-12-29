/*
 * EnergyBallLife.h
 *
 *  Created on: Apr 19, 2012
 *      Author: David Zhang
 */

#ifndef ENERGYBALLLIFE_H_
#define ENERGYBALLLIFE_H_

#include "Item.h"

class EnergyBallLife: public Item {
public:
	EnergyBallLife(); // life energy

	void move(); // overriding superclass

	void randomlyHide(); // virtual fn implemented
	int getEnergyLevel() { return 4; };

protected:
	std::string file();
};

#endif /* ENERGYBALLLIFE_H_ */
