/*
 * Asteroid.h
 *
 *  Created on: Apr 4, 2012
 *      Author: David Zhang
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "FallingObject.h"

class Asteroid: public FallingObject {
public:
	Asteroid();

	void resetState();
};


#endif /* ASTEROID_H_ */
