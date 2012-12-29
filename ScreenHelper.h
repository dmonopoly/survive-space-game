/*
 * ScreenHelper.h
 * 	Sets WIDTH and HEIGHT of game window and has helpers for other screen properties.
 *
 *  Created on: Apr 3, 2012
 *      Author: David Zhang
 */


#ifndef SCREENHELPER_H_
#define SCREENHELPER_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <QPainter>
#include <QFont>

// Important variables that determine width and height of game window
const int WIDTH = 900;
const int HEIGHT = 700;

class ScreenHelper {
	QColor color;
	QFont font;

public:
	ScreenHelper() {
		color = Qt::green; // pen color
		font = QFont("Courier", 15, QFont::DemiBold);
	}

	void setColor(QColor c) { color = c; }

	void printCenteredMsg(std::string &msg, QPainter &painter, int offset);

	void printTopLeftMsg(std::string &msg, QPainter &painter);

	int getMessageCol() {
		return WIDTH*1/5; // don't put parentheses around constant... makes it zero...
	}

	int getMessageRow() {
		return HEIGHT*1/4;
	}

	int getRandomCol() {
		return rand() % WIDTH ; // 0 to (WIDTH-1)
	}

	int getRandomRow() {
		return rand() % HEIGHT; // 0 to (HEIGHT-1)
	}

	int getRandomRowOnTopFraction(float frac) { // frac < 1
		return rand() % ((int) (HEIGHT*frac));
	}

	int getRandomRowOnTopHalf() {
		return rand() % (HEIGHT/2);
	}

	int getRandomRowOnBottomHalf() {
		return ( rand() % (HEIGHT/2) ) + HEIGHT/2;
	}

	int widthOfAsteroid() {
		return 50; // number of pixels for width of asteroids image file
	}

	int widthOfItem() {
		return 50;
	}

};

#endif /* SCREENHELPER_H_ */
