/*
 * Terrier.h
 *
 *  Created on: Apr 19, 2012
 *      Author: David Zhang
 */

#ifndef TERRIER_H_
#define TERRIER_H_

#include "Attacker.h"
#include <iostream>
using namespace std;

class Terrier: public Attacker {
public:
	Terrier();

	void loadImage(); // virtual fn implemented
};

#endif /* TERRIER_H_ */


