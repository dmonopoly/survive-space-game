/*
 * Player.h
 *
 *  Created on: Apr 2, 2012
 *      Author: David Zhang
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Object.h"

class Player: public Object {
public:
	Player();

	void move(Direction d);

	void resetState();
	void loadNormalImage();
	void fadeImage();

private:
	const static std::string NORMAL_SHIP_IMAGE;
	const static std::string FADED_SHIP_IMAGE;

	int movementInterval;
//	bool on;
//	int speed;
//	bool isMovingN, isMovingS, isMovingE, isMovingW;

	void timerEvent(QTimerEvent *event);
};

#endif /* PLAYER_H_ */
