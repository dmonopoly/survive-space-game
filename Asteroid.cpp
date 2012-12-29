/*
 * Asteroid.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: David Zhang
 */

#include "Asteroid.h"

Asteroid::Asteroid(): FallingObject() {
	image.load("asteroid2.png"); // image setup

	rect = image.rect();
	resetState();
}


// Resets location of asteroid and turns asteroid off
void Asteroid::resetState() {
	int c = helper.getRandomCol();
	int r = helper.getRandomRowOnTopFraction(.78);
	rect.moveCenter(QPoint(c, r));

	setOn(false);
}
