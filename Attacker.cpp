/*
 * Attacker.cpp
 *
 *  Created on: Apr 15, 2012
 *      Author: David Zhang
 */

#include "Attacker.h"

#include <iostream>
using namespace std;

Attacker::Attacker(): FallingObject() {
	visible = false;
	setTimerLevel(120); // different speed

	shotTimerLevel = 50;
	shotTimer = shotTimerLevel;
}

Attacker::~Attacker() {
	// Clean up projectiles
	for (unsigned int i=0; i<projectiles.size(); i++) {
		delete projectiles[i]; // safely delete
		projectiles[i] = NULL; // clean up pointer
	}
}

// Resets location and attacker off
void Attacker::resetState() {
	int c = helper.getRandomCol();
	int r = helper.getRandomRowOnTopFraction(.78);
	rect.moveCenter(QPoint(c, r));

	setOn(false);
}

void Attacker::timerEvent(QTimerEvent *event) {
	FallingObject::timerEvent(event); // call super class method

	if (visible) {
		shotTimer--;
		if (shotTimer == 0) {
			shotTimer = shotTimerLevel;
			fire();
		}

		// check projectiles for exhausted
		for (unsigned int i=0; i<projectiles.size(); i++) {
			if (projectiles[i]->isExhausted()) {
				delete projectiles[i]; // safely delete
				projectiles[i] = NULL; // clean up pointer
				projectiles.erase(projectiles.begin()+i); // remove from vector
				i--; // compensate for deleted projectile ... CHECK HERE
				cout << "projectile erased" << endl;
			}
		}
	}

}

void Attacker::fire() {
	Projectile *p = new Projectile;

	p->setLocation(this->rect.center());
	p->setTarget(target);
	p->launch();

	projectiles.push_back(p);
}

void Attacker::updateTargetLocation(QPoint p) {
	target = p;
}

void Attacker::setOn(bool b) {
	FallingObject::setOn(b); // super class call

	// In addition, turn off/on projectiles
	for (unsigned int i=0; i<projectiles.size(); i++) {
		projectiles[i]->setOn(b);
	}
}

// This makes the attacker visible - i.e., ensures image loaded properly. Before, image is null.
void Attacker::setVisible(bool b) {
	visible = b;
	if (visible) {
		loadImage();
	}
}
