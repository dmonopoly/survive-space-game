/*
 * Player.cpp
 *
 *  Created on: Apr 2, 2012
 *      Author: David Zhang
 */

#include "Player.h"

#include <iostream>
using namespace std;

const string Player::NORMAL_SHIP_IMAGE = "spaceship.png";
const string Player::FADED_SHIP_IMAGE = "spaceship-faded.png";

Player::Player(): Object() {
	direction = N; // direction not important for player at this time
	movementInterval = 25;

//	on = false;
//	speed = 0;
//	isMovingN = false;
//	isMovingE = false;
//	isMovingS = false;
//	isMovingW = false;

	loadNormalImage();

	rect = image.rect();
	resetState();
}

void Player::loadNormalImage() {
	image.load(NORMAL_SHIP_IMAGE.c_str());
}

void Player::fadeImage() {
	image.load(FADED_SHIP_IMAGE.c_str());
}

// Moves player in direction
// Note: void QRect::translate ( int dx, int dy )
// -> Moves the rectangle dx along the x axis and dy along the y axis, relative to the current position.
// -> Positive values move the rectangle to the right and down
void Player::move(Direction direction) {
    if (direction == N && rect.top() > movementInterval) {
    	rect.translate(0, -movementInterval);
    } else if (direction == E && (WIDTH - rect.right()) > movementInterval) {
    	rect.translate(movementInterval, 0);
    } else if (direction == S && (HEIGHT - rect.bottom()) > movementInterval) {
    	rect.translate(0, movementInterval);
    } else if (direction == W && rect.left() > movementInterval) {
    	rect.translate(-movementInterval, 0);
    }
    //else
    	//cout << "Object won't move because it has reached the edge." << endl;

}

// Repositions player at starting spot
void Player::resetState() {
	image.load(NORMAL_SHIP_IMAGE.c_str());
	rect.moveCenter(QPoint(WIDTH/2, HEIGHT/2));
}

void Player::timerEvent(QTimerEvent *event) {
	// Do nothing
}

//void Player::setOn(bool b) {
//	on = b;
//	if (on)
//		timerId = startTimer(timerLevel);
//	else
//		killTimer(timerId);
//}
