/*
 * Leviathan.h
 *
 *  Created on: Apr 16, 2012
 *      Author: David Zhang
 */

#ifndef LEVIATHAN_H_
#define LEVIATHAN_H_

#include "Attacker.h"
#include <iostream>
using namespace std;

class Leviathan: public Attacker {
public:
	Leviathan();

	void loadImage(); // virtual fn implemented
};

#endif /* LEVIATHAN_H_ */
