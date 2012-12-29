/*
 * EnergyBallLife.cpp
 *
 *  Created on: Apr 19, 2012
 *      Author: David Zhang
 */

#include "EnergyBallLife.h"

#include <iostream>
using namespace std;

EnergyBallLife::EnergyBallLife(): Item() {
	//	setTimerLevel(90); set here if you want different speed

	obtained = false;
	image.load(file().c_str());

	rect = image.rect();
	resetState();

}

// Overriding superclass
void EnergyBallLife::move() {
	if ((HEIGHT - rect.bottom()) > movementInterval) {
		rect.translate(0, movementInterval);
	} else { // move back to top
		obtained = false;
		int c = helper.getRandomCol();
		rect.moveCenter(QPoint(c, 0));

		randomlyHide();
	}
}

string EnergyBallLife::file() {
	return "purple-energy-ball.png";
}

// 1 in 12 chance of this ball appearing
void EnergyBallLife::randomlyHide() {
	int x = rand() % 10; // 0-11
	if (x != 0)
		obtained = true; // hide
}
