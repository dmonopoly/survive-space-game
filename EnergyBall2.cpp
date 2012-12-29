/*
 * EnergyBall2.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: David Zhang
 */

#include "EnergyBall2.h"
#include <iostream>
using namespace std;

EnergyBall2::EnergyBall2(): Item() {
//	setTimerLevel(90); set here if you want different speed

	obtained = false;
	image.load(file().c_str());

	rect = image.rect();
	resetState();
}

// Overriding superclass
void EnergyBall2::move() {
	if ((HEIGHT - rect.bottom()) > movementInterval) {
		rect.translate(0, movementInterval);
	} else { // move back to top
		obtained = false;
		int c = helper.getRandomCol();
		rect.moveCenter(QPoint(c, 0));

		randomlyHide();
	}
}

string EnergyBall2::file() {
	return "blue-energy-ball.png";
}

// 1 in 2 chance of this ball appearing
void EnergyBall2::randomlyHide() {
	int x = rand() % 2; // 0-1
	if (x != 0)
		obtained = true; // hide
}
