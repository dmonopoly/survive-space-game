/*
 * Item.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: David Zhang
 */

#include "Item.h"

// 1->yellow, 2->blue, 3->white
Item::Item(): FallingObject() {
	setTimerLevel(90); // initial speed of items
}

void Item::move() {
	if ((HEIGHT - rect.bottom()) > movementInterval) {
		rect.translate(0, movementInterval);
	} else { // move back to top
		obtained = false;
		int c = helper.getRandomCol();
		rect.moveCenter(QPoint(c, 0));
	}
}

// Resets location and turns off
void Item::resetState() {
	int c = helper.getRandomCol();
	int r = helper.getRandomRowOnTopFraction(.78);
	rect.moveCenter(QPoint(c, r));

	setOn(false);
}
