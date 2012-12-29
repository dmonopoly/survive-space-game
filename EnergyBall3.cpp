/*
 * EnergyBall3.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: David Zhang
 */

#include "EnergyBall3.h"
#include <iostream>
using namespace std;

EnergyBall3::EnergyBall3(): Item() {
	setTimerLevel(95); // moves faster than others

	obtained = false;
	image.load(file().c_str());

	rect = image.rect();
	resetState();
}

// Overriding
void EnergyBall3::move() {
	if ((HEIGHT - rect.bottom()) > movementInterval) {
		rect.translate(0, movementInterval);
	} else { // move back to top
		obtained = false;
		int c = helper.getRandomCol();
		rect.moveCenter(QPoint(c, 0));

		randomlyHide();
	}
}

string EnergyBall3::file() {
	return "white-energy-ball.png";
}

// 1 in 5 chance of this ball appearing
void EnergyBall3::randomlyHide() {
	int x = rand() % 6; // 0-5
	if (x != 0)
		obtained = true; // hide
}
