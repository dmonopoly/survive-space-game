/*
 * Attacker.h
 *
 *  Created on: Apr 15, 2012
 *      Author: David Zhang
 */

#ifndef ATTACKER_H_
#define ATTACKER_H_

#include <vector>

#include "FallingObject.h"
#include "Projectile.h"

class Attacker: public FallingObject {
public:
	Attacker();
	~Attacker();
	void resetState();

	void setVisible(bool b);
	bool isVisible() { return visible; };
	void updateTargetLocation(QPoint);

	void setOn(bool); // override

	// Return projectiles directly
	std::vector<Projectile *>& getProjectiles() { return projectiles; };

protected:
	bool visible; // attackers are hidden in the background; made visible when level reached; note that "on" is for pause/unpause
	std::vector<Projectile *> projectiles;

	int shotTimer; // when this reaches 0, the attacker fires
	int shotTimerLevel; // keep track of original level of shotTimer so shotTimer can reset properly; change this to change speed of projectile
	QPoint target;

	virtual void timerEvent(QTimerEvent *event);
	virtual void loadImage() = 0;
	virtual void fire();
};

#endif /* ATTACKER_H_ */
