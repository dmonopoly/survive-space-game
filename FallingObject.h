/*
 * FallingObject.h
 *
 *  Created on: Apr 4, 2012
 *      Author: David Zhang
 */

#ifndef FALLINGOBJECT_H_
#define FALLINGOBJECT_H_

#include "Object.h"

class FallingObject: public Object {
public:
	FallingObject();
	virtual void move();

	void setOn(bool);
	void setTimerLevel(int i);
	int getTimerLevel() { return timerLevel; };

protected:
	virtual void timerEvent(QTimerEvent *event);

	int movementInterval;

private:
	Direction direction; // redefines direction to be private because subclasses cannot modify this
	bool on;
	int timerLevel;
};


#endif /* FALLINGOBJECT_H_ */
