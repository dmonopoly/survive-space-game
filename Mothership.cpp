/*
 * Mothership.cpp
 *
 *  Created on: Apr 19, 2012
 *      Author: David Zhang
 */

#include "Mothership.h"
#include <QSound>

Mothership::Mothership() {
	setTimerLevel(200); // movement speed of mothership is slower
	shotTimerLevel = 12; // firing rate is faster - must be substantially faster (lower) because timer runs based on setTimerLevel here, which is very slow

	rect = image.rect();
	resetState();
}

void Mothership::loadImage() {
	image.load("attacker3.png");
	rect = image.rect();
}

void Mothership::fire() {
	Attacker::fire();
	// Make recently added projectile of mothership special
	projectiles[projectiles.size()-1]->setImage("red-energy-ball.png");

	QSound::play("rocket.wav"); // play firing sound!
}
