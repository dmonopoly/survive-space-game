/*
 * Leviathan.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: David Zhang
 */

#include "Leviathan.h"

Leviathan::Leviathan() {
//	image.load("attacker.png");
	rect = image.rect();
	resetState();
}

void Leviathan::loadImage() {
	image.load("attacker.png");
	rect = image.rect();
}
