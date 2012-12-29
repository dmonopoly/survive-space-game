/*
 * Projectile.cpp
 *
 *  Created on: Apr 15, 2012
 *      Author: David Zhang
 */

#include "Projectile.h"

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

Projectile::Projectile(): Object() { // moment a projectile is created, it starts moving from origin to target
	on = false; // must call launch()
	exhausted = false;

	timerLevel = 45; // faster than falling objects
	movementInterval = 6; // a little faster than falling objects
	image.load("yellow-energy-ball.png");

	rect = image.rect();
}

void Projectile::timerEvent(QTimerEvent *event) {
	if (on) {
		move();
		if (location.x() == WIDTH || location.x() == 0 || location.y() == HEIGHT || location.y() == 0)
			exhausted = true;
	}
}

void Projectile::setLocation(QPoint p) {
	location = p;
}

void Projectile::setTarget(QPoint p) {
	target = p;
}

// Starts timer and sets on to true
void Projectile::launch() {
	try {
		rect.moveCenter(location); // move to starting location
		int totalYDif = target.y() - location.y();
		int totalXDif = target.x() - location.x();

		if (totalYDif == 0) { // prevent divide by zero error
			dy = 0;
			dx = movementInterval;
		} else if (totalXDif == 0) {
			dx = 0;
			dy = movementInterval;
		} else { // fancy math here
			// totalYDif^2 + totalXDif^2 should equal movementInterval^2
			float tempdy = sqrt(pow(movementInterval,2) / ( pow(totalXDif/totalYDif, 2)+1) ); // should be positive
			float tempdx = tempdy*abs(totalXDif) / abs(totalYDif); // should be positive

			// Check 0. Okay to be slightly inaccurate.
			if (tempdy < 1 || tempdx < 1) {
				tempdy+=1;
				tempdx+=1;
			}

			dx = tempdx;
			dy = tempdy;

			// Check for + and -
			if (totalXDif > 0 && totalYDif > 0) { // case 1
				// Calculation is fine.
			} else if (totalXDif > 0 && totalYDif < 0) { // case 2
				dy = -dy;
			} else if (totalXDif < 0 && totalYDif > 0) { // case 3
				dx = -dx;
			} else { // both negative - case 4
				dx = -dx;
				dy = -dy;
			}
		}

		setOn(true);
	} catch (...) {
		// Safety net
	}
}

// Moves from location to target, and updates location
void Projectile::move() {
	rect.translate(dx, dy);
}

// Like FallingObject's setOn - changes timer appropriately
void Projectile::setOn(bool b) {
	on = b;
	if (on)
		timerId = startTimer(timerLevel);
	else
		killTimer(timerId);
}

void Projectile::setImage(std::string s) {
	image.load(s.c_str());
}
