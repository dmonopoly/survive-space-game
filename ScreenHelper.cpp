/*
 * ScreenHelper.cpp
 *
 *  Created on: Apr 6, 2012
 *      Author: David Zhang
 */
#include "ScreenHelper.h"

#include <QLabel>
#include <QFont>

#include <iostream>
using namespace std;

// Prints msg at center, with offset pixels down
void ScreenHelper::printCenteredMsg(std::string &msg, QPainter &painter, int offset) {
	QFontMetrics fm(font);
	int textWidth = fm.width(msg.c_str());

	painter.setPen(color);
	painter.setFont(font);

	painter.translate(QPoint(WIDTH/2, HEIGHT/2+offset)); // translates the coordinate SYSTEM
	painter.drawText(-textWidth/2, 0, msg.c_str());
	painter.translate(QPoint(-WIDTH/2, -(HEIGHT/2+offset))); // translate back
}

void ScreenHelper::printTopLeftMsg(std::string &msg, QPainter &painter) {
	painter.setPen(color);
    painter.setFont(font);

    QPoint topLeft(5,10);
    painter.drawText(topLeft, msg.c_str());
}
