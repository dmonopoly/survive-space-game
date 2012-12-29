/*
 * Object.h
 *
 *  Created on: Apr 2, 2012
 *      Author: David Zhang
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "ScreenHelper.h"

#include <QObject>
#include <QImage>
#include <QRect>

enum Direction { N, E, S, W };

class Object: public QObject { // extends this so an object can have a timer

public:
	Object();

	bool collidedWith(Object &obj);
	bool tooCloseTo(Object &obj);

	QRect getRect();
	QImage& getImage();

protected:
	int timerId;
	ScreenHelper helper;
	Direction direction;
	QImage image;
	QRect rect;

	virtual void timerEvent(QTimerEvent *event) = 0;
};

#endif /* OBJECT_H_ */
