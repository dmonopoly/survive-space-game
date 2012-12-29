/*
 * Projectile.h
 *
 *  Created on: Apr 15, 2012
 *      Author: David Zhang
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "ScreenHelper.h"
#include "Object.h"

class Projectile: public Object {
public:
	Projectile();

	void setLocation(QPoint);
	void setTarget(QPoint);
	void launch();

	void setOn(bool b);
	bool isExhausted() { return exhausted; };

	void setImage(std::string);

private:
	QPoint location; // starting location and present location
	QPoint target; // target to move toward
	int dx, dy; // for translate(dx, dy) to move projectile
	bool on;
	bool exhausted;
	int movementInterval;

	int timerLevel;

	void move();
	void timerEvent(QTimerEvent *event);
};

#endif /* PROJECTILE_H_ */
