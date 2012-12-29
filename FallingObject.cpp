/*
 * FallingObject.cpp
 *
 *  Created on: Apr 4, 2012
 *      Author: David Zhang
 */

#include "FallingObject.h"

#include <iostream>
using namespace std;

FallingObject::FallingObject(): Object() {
	direction = S; // direction is south b/c these objects fall
	on = false; // true means object is moving
	timerLevel = 100;
	movementInterval = 5; // change this to level up
}

void FallingObject::move() {
	if ((HEIGHT - rect.bottom()) > movementInterval) {
		rect.translate(0, movementInterval);
	} else { // move back to top
		int c = helper.getRandomCol();
		rect.moveCenter(QPoint(c, 0));
	}
}

void FallingObject::timerEvent(QTimerEvent *event) {
	if (on) {
		move();
	}
}


void FallingObject::setOn(bool b) {
	on = b;
	if (on)
		timerId = startTimer(timerLevel);
	else
		killTimer(timerId);
}

// Sets timer level and restarts internal timer
void FallingObject::setTimerLevel(int i) {
	timerLevel = i;
	setOn(false);
	setOn(true);
}
