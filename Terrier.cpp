/*
 * Terrier.cpp
 *
 *  Created on: Apr 19, 2012
 *      Author: David Zhang
 */

#include "Terrier.h"

Terrier::Terrier() {
	setTimerLevel(90);

	rect = image.rect();
	resetState();
}

void Terrier::loadImage() {
	image.load("attacker2.png");
	rect = image.rect();
}
