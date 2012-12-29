/*
 * EnergyBall1.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: David Zhang
 */

#include "EnergyBall1.h"
#include <iostream>
using namespace std;

EnergyBall1::EnergyBall1(): Item() {
	obtained = false;
	image.load(file().c_str());

	rect = image.rect();
	resetState();
}

string EnergyBall1::file() {
	return "green-energy-ball.png";
}

void EnergyBall1::randomlyHide() {
	// not needed for most basic item
}
