/*
 * Object.cpp
 *
 *  Created on: Apr 2, 2012
 *      Author: David Zhang
 */

#include "Object.h"

#include <iostream>
using namespace std;

Object::Object(): QObject(), helper() { // need to pass parent?
	// safety settings
	direction = N;
	timerId = -1;
}

bool Object::collidedWith(Object &obj) {
	return this->getRect().intersects(obj.getRect());
}

// Used in placement of asteroids so player is not too close to an asteroid at start
bool Object::tooCloseTo(Object &obj) {
	QRect r = this->getRect();
	int bottomCoordinate = r.bottom();
	r.setHeight(r.height()+200); // adds height to rect, not changing top but changing bottom edge
	r.setBottom(bottomCoordinate); // move rect back up so bottom edge unchanged, top cleared

	return r.intersects(obj.getRect());
}

QRect Object::getRect() {
	return rect;
}

QImage& Object::getImage() {
	return image;
}
