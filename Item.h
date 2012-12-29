/*
 * Item.h
 *
 *  Created on: Apr 8, 2012
 *      Author: David Zhang
 */

#ifndef ITEM_H_
#define ITEM_H_

#include "FallingObject.h"

class Item: public FallingObject {
public:
	Item();

	void resetState();

	virtual int getEnergyLevel() = 0;
	virtual void randomlyHide() = 0;

	bool isObtained() { return obtained; }
	void disappear() { obtained = true; }

	void move();

protected:
	virtual std::string file() = 0; // returns file of image
	bool obtained; // to determine if item should be hidden
};

#endif /* ITEM_H_ */
