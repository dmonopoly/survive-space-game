/*
 * Mothership.h
 *
 *  Created on: Apr 19, 2012
 *      Author: David Zhang
 */

#ifndef MOTHERSHIP_H_
#define MOTHERSHIP_H_

#include "Attacker.h"
#include <QSound>
#include <iostream>
using namespace std;

class Mothership: public Attacker {
public:
	Mothership();

	void loadImage(); // virtual fn implemented

protected:
	void fire(); // overriding for sound
};

#endif /* MOTHERSHIP_H_ */
