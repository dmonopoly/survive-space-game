#include "Game.h"

#include <QPainter>
#include <QPalette>
#include <QSound>
#include <QApplication>

#include <sstream>
#include <iostream>
using namespace std;

const string Game::BACKGROUND1 = "background1.jpeg";
const string Game::BACKGROUND2 = "background2.jpg";
const string Game::BACKGROUND3 = "background3.jpg";

// Music and sound setup
QSound music("Twilight_Techno_piano.wav");
QSound crash("crash.wav"); // when player crashes into asteroid
QSound enableship("enableship.wav"); // activating ship at beginning of game
QSound explosion("enemy_explosion.wav"); // when the player dies by an enemy's fire
QSound levelup("level2.wav"); // sound when the player levels up
QSound mothershipArrivalSound("levelonestart.wav"); // when mothership arrives

Game::Game(QWidget *parent): QWidget(parent), helper() {
    state = MAIN_MENU;
    player = new Player();
    mainTimerLevel = 50; // frame rate, essentially

    clearFallingObjects();
    resetGame(); // reset properties like lives, score, level, etc.
    // also prepares objects' position in background
}

Game::~Game() {
	delete player;
	clearFallingObjects();
}

// Qt uses this to handle painting; required method
void Game::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    if (state == MAIN_MENU) {
        mainMenu(painter); // detection for space key starts timer and sets state to GAME_ON
    } else if (state == GAME_ON) {
    	continueGame(painter); // essentially keeps redrawing objects; timer always on
    } else if (state == GAME_OVER) {
    	gameOver(painter); // show game over screen
    	killTimer(mainTimerId); // stop timer
    	// processing of space key here returns state to MAIN_MENU
    } else { // PAUSED

    }
}

// Calls a function after a set time period mainTimerId
// Note that this is only run when state is GAME_ON
void Game::timerEvent(QTimerEvent *event) {
    //move objects - maybe I don't move them here. They should move on their own. How do I control that, though?
    detectCollisions();
    repaint();
}

// Qt calls this automatically when a key is pressed
void Game::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_A:
            player->move(W);
            break;
        case Qt::Key_W:
        	player->move(N);
            break;
        case Qt::Key_D:
        	player->move(E);
            break;
        case Qt::Key_S:
        	player->move(S);
            break;
        case Qt::Key_P:
            dealWithPause();
            break;
        case Qt::Key_Q: {
        	if (state == GAME_ON) // should not do anything if paused
            	state = GAME_OVER;
            break;
        }
        case Qt::Key_Space:
        	processSpaceKey(); // starts game, continues after game over screen
        	break;
        default:
            QWidget::keyPressEvent(event); // calls keyPressEvent of event
            break;
    }
}

void Game::preparePlayer() {
	player->resetState();
}

// Sets object positions (rect positions, specifically) for game beginning; shouldn't need painter
// Used when a player dies and the screen resets, as well
// Does not turn falling objects on
// post: falling objects placed, but turned off
void Game::prepareObjects() {
	// Background
	palette.setBrush(this->backgroundRole(), QBrush(QImage(BACKGROUND1.c_str())));
	this->setPalette(palette);

	// Player
	preparePlayer();

	// Asteroids
	if (asteroids.empty()) { // Check if asteroids already made from previous life
		unsigned int numAsteroids = (WIDTH/helper.widthOfAsteroid())*5/10; // fraction of width that has asteroids
		Asteroid *a;
		for (unsigned int i=0; i < numAsteroids; i++) {
			a = new Asteroid();
			asteroids.push_back(a); // add to vector
			a->resetState();
			while (a->tooCloseTo(*player)) // in case the asteroid and player are too close
				a->resetState();
		}
	} else { // Reset existing asteroids, turn them off
		for (unsigned int i=0; i < asteroids.size(); i++) {
			asteroids[i]->resetState();
			while (asteroids[i]->tooCloseTo(*player)) // in case the asteroid and player are too close
				asteroids[i]->resetState();
		}
	}

	// Items
	if (items.empty()) {
		unsigned int numItems = 5; //(WIDTH/helper.widthOfItem())*1/15; // fraction of width that has items
		Item *a;
		for (unsigned int i=0; i < numItems; i++) {
			if (i <= 1)
				a = new EnergyBall1();
			else if (i == 2) {
				a = new EnergyBall2();
				a->randomlyHide();
			} else if (i == 3) {
				a = new EnergyBall3();
				a->randomlyHide(); // hide the best energy ball at random, so it appears occasionally
			} else {
				a = new EnergyBallLife();
				a->randomlyHide();
			}

			items.push_back(a); // add to vector
			a->resetState();
			while (a->tooCloseTo(*player)) // in case the item and player are too close
				a->resetState();
		}
	} else { // Reset existing items, turn them off
		for (unsigned int i=0; i < items.size(); i++) {
			items[i]->resetState();
			while (items[i]->tooCloseTo(*player)) // in case the item and player are too close
				items[i]->resetState();
		}
	}

	// Attackers
	if (attackers.empty()) {
		Attacker *a;
		a = new Leviathan();
		attackers.push_back(a);

		a = new Terrier();
		attackers.push_back(a);

		a = new Mothership();
		attackers.push_back(a);
	} else { // Reset existing attackers, turn them off
		for (unsigned int i=0; i < attackers.size(); i++) {
			attackers[i]->resetState();
		}
	}
}

// Pre: objects already drawn
// Deals with hitting the space key, which starts the game or proceeds after the game over screen
void Game::processSpaceKey() {
	if (state == MAIN_MENU) {
		startGame();
	} else if (state == GAME_OVER) {
		// clearFallingObjects should have already happened in gameOver
		resetGame();
		state = MAIN_MENU;
		repaint(); // need to call repaint because timerEvent is off and so paintEvent won't be reached
	}
}

// Turns state to GAME_ON and makes objects fall
// Called from states of MAIN_MENU
void Game::startGame() {
	state = GAME_ON;
	setFallingObjectsOn(true); // make objects fall

	// Starts a timer and returns a timer identifier, or returns zero if it could not start a timer.
	mainTimerId = startTimer(mainTimerLevel);

	// Start the music!
	music.play();
	enableship.play(); // ship enabling sound
}
// Called in timerEvent when game state is GAME_ON
// (Any methods that have a painter as a parameter are called from paintEvent)
// Goes through possible state flags, like justLostLife
// Draws objects; note that the actual drawing does not occur until after this method terminates
void Game::continueGame(QPainter &painter) {
	if (justLostLife) {
		loseLife(painter);
		invCount = 50;
		player->fadeImage();
	}

	// Deal with level, updating level and setting msg as appropriate
	levelCheck();

	// If player is in invincible state (right after death), count down and ease player into his next life
	if (invCount > 0) {
		msg = "LIFE LOST";
		invCount--;
		if (invCount == 0)
			player->loadNormalImage();
	}

	// Show messages if msg is set
	messageCheck(painter);

	// Draw objects normally
	drawObjects(painter);

	// Pass player coordinates to attackers
	passPlayerInfoToAttackers();

	// Updates score & lives
	updateScoreDisplay(painter);
}

void Game::drawObjects(QPainter &painter) {
	// Draw asteroids, items, attackers, player appropriately

	for (unsigned int i=0; i < asteroids.size(); i++)
		painter.drawImage(asteroids[i]->getRect(), asteroids[i]->getImage());

	for (unsigned int i=0; i < items.size(); i++)
		if (!items[i]->isObtained())
			painter.drawImage(items[i]->getRect(), items[i]->getImage());

	for (unsigned int i=0; i < attackers.size(); i++) {
		if (attackers[i]->isVisible()) {
			painter.drawImage(attackers[i]->getRect(), attackers[i]->getImage());
			// Draw the attackers' projectiles
			vector<Projectile *> projectiles = attackers[i]->getProjectiles(); // Danger - be careful.
			for (unsigned int i=0; i < projectiles.size(); i++) {
				painter.drawImage(projectiles[i]->getRect(), projectiles[i]->getImage());
			}
		}
	}

	painter.drawImage(player->getRect(), player->getImage());
}

// Called in timerEvent when game state is MAIN_MENU
void Game::mainMenu(QPainter &painter) {
	drawObjects(painter);
	string msg = "Main menu";
	helper.printCenteredMsg(msg, painter, -25);

	msg = "Press space to start a new game.";
	helper.printCenteredMsg(msg, painter, 25);
}

void Game::dealWithPause() {
	if (state == PAUSED) {
		// Unpause
		mainTimerId = startTimer(mainTimerLevel);
		setFallingObjectsOn(true); // turns on falling objects
		state = GAME_ON;
	} else if (state == GAME_ON) {
		// Pause
		killTimer(mainTimerId);
		setFallingObjectsOn(false); // turns off falling objects
		state = PAUSED;
	}
}

// Important sequence in game: gameOver (clearFallingObjects within) -> process space key -> resetGame
void Game::gameOver(QPainter &painter) {
	clearFallingObjects();

	music.stop();

	helper.setColor(Qt::green);

	string msg = "G A M E  O V E R";
	helper.printCenteredMsg(msg, painter, -25);

	stringstream ss;
	ss << score << " points, Reached Level " << level << " | Hit space to continue.";

	msg = ss.str();
	helper.printCenteredMsg(msg, painter, 25);
}

// Resets various properties
// called after gameOver screen, and once the space key is pressed; then program returns to the main menu
void Game::resetGame() {
    msg = "";
    msgTracker = 0;
    invCount = 0;

    lives = 3;
    score = 0;
    level = 1;
    justLostLife = false; // ensure this is false so you don't start with one fewer lives

    prepareObjects();
}

// Updates top left score and lives
void Game::updateScoreDisplay(QPainter &painter) {
    stringstream ss;
    ss << "Score: " << score << " | Level: " << level << " | Lives: " << lives;
    string msg = ss.str();
	helper.printTopLeftMsg(msg, painter);

	score++;
}

// Speeds up all falling objects
void Game::speedUpFallingObjects() {
	for (unsigned int i=0; i < asteroids.size(); i++) {
		asteroids[i]->setTimerLevel(asteroids[i]->getTimerLevel()-10); // number here is key to how quickly this speeds up
	}

	for (unsigned int i=0; i < items.size(); i++) {
		items[i]->setTimerLevel(items[i]->getTimerLevel()-10);
	}

	for (unsigned int i=0; i < attackers.size(); i++) {
		attackers[i]->setTimerLevel(attackers[i]->getTimerLevel()-10);
	}
}

// Used to speed up falling objects, which happens after leveling up - except attackers
void Game::setFallingObjectsTimerLevel(int lvl) {
	for (unsigned int i=0; i < asteroids.size(); i++) {
		asteroids[i]->setTimerLevel(lvl);
	}

	for (unsigned int i=0; i < items.size(); i++) {
		items[i]->setTimerLevel(lvl);
	}
}

void Game::setFallingObjectsOn(bool b) {
	// Asteroids
	for (unsigned int i=0; i < asteroids.size(); i++) {
		asteroids[i]->setOn(b);
	}

	// Items
	for (unsigned int i=0; i < items.size(); i++) {
		items[i]->setOn(b);
	}

	// Attackers
	for (unsigned int i=0; i < attackers.size(); i++) {
		attackers[i]->setOn(b);
	}
}

// Detects collisions and sets collision flags
void Game::detectCollisions() {
	if (invCount == 0) { // invincible count; when zero, player is not invincible; used when player just died and has some invincibility
		bool cont = true; // "shouldContinue"

		// Items
		for (unsigned int i=0; i < items.size(); i++) {
			if (!items[i]->isObtained() && player->collidedWith(*items[i])) {
				respondToItem(items[i]);
				cont = false;
				break;
			}
		}

		// Asteroids
		if (cont) { // don't check these if already collided
			for (unsigned int i=0; i < asteroids.size(); i++) {
				if (player->collidedWith(*asteroids[i])) {
					justLostLife = true;
					cont = false;
					crash.play(); // crash sound!
					break;
				}
			}
		}

		// Attackers
		if (cont) { // don't check these if already collided
			for (unsigned int i=0; i < attackers.size(); i++) {
				if (player->collidedWith(*attackers[i])) {
					justLostLife = true;
					cont = false;
					crash.play(); // crash sound!
					break;
				}

				// Check this attacker's projectiles
				if (cont) {
					vector<Projectile *> projectiles = attackers[i]->getProjectiles(); // Danger - be careful.
					for (unsigned int i=0; i < projectiles.size(); i++) {
						if (player->collidedWith(*projectiles[i])) {
							justLostLife = true;
							cont = false;
							explosion.play(); // play sound for death by enemy attack!
							break;
						}
					}
				}
			} // end attacker for loop
		}

	} // end if invCount
}

// Changes display according upon life lost
void Game::loseLife(QPainter &painter) {
	if (justLostLife) {
		lives--;
		if (lives != 0) {
			updateHelperColorBasedOnLives();
			preparePlayer();
		} else {
			state = GAME_OVER;
		}
		justLostLife = false;
	}
}

void Game::updateHelperColorBasedOnLives() {
	switch(lives) {
	case 3: // not really called anywhere, but for safety
		helper.setColor(Qt::green);
		break;
	case 2:
		helper.setColor(Qt::yellow);
		break;
	case 1:
		helper.setColor(Qt::red);
		break;
	}
}

void Game::respondToItem(Item *item) {
	if (item->getEnergyLevel() == 3) {
		score += 100;
		msg = "+100 POINTS";
	} else if (item->getEnergyLevel() == 2) {
		score += 50;
		msg = "+50 POINTS";
	} else if (item->getEnergyLevel() == 1) {
		score += 25;
		msg = "+25 POINTS";
	} else if (item->getEnergyLevel() == 4) { // life
		lives++;
		msg = "+1 LIFE";
	} else {
		// shouldn't happen
	}


	// Remove item
	item->disappear();
	repaint(); // manually call this to hide item
}

void Game::levelCheck() {
	int firstLevel = 400;
	int scoreInterval = 400;

	if (level == 1 && score > firstLevel) {
		level++;
		speedUpFallingObjects();
		msg = "LEVEL UP!!!";
		levelup.play();
	} else if (level == 2 && score > firstLevel+scoreInterval) {
		level++;
		speedUpFallingObjects();

		// Show leviathan!
		makeLeviathanVisible();

		msg = "LEVEL UP - Beware...";

		levelup.play();
	} else if (level == 3 && score > firstLevel+scoreInterval*2) {
		level++;
		speedUpFallingObjects();
		msg = "LEVEL UP - NEW WORLD REACHED";

		// set background
		palette.setBrush(this->backgroundRole(), QBrush(QImage(BACKGROUND2.c_str())));
		this->setPalette(palette);

		levelup.play();
	} else if (level == 4 && score > firstLevel+scoreInterval*3) {
		level++;
		speedUpFallingObjects();

		// Show terrier!
		makeTerrierVisible();

		msg = "LEVEL UP!!!";

		levelup.play();
	} else if (level == 5 && score > firstLevel+scoreInterval*4) {
		level++;
		speedUpFallingObjects();
		msg = "LEVEL UP!!!";

		levelup.play();
	} else if (level == 6 && score > firstLevel+scoreInterval*5) {
		level++;
		speedUpFallingObjects();
		msg = "LEVEL UP - NEW WORLD REACHED";

		// set background
		palette.setBrush(this->backgroundRole(), QBrush(QImage(BACKGROUND3.c_str())));
		this->setPalette(palette);

		levelup.play();
	} else if (level == 7 && score > firstLevel+scoreInterval*6) {
		level++;
		speedUpFallingObjects();

		// Show mothership!
		makeMothershipVisible();

		msg = "LEVEL UP!!!";

		levelup.play();
	}
}

void Game::messageCheck(QPainter &painter) {
	if (msg != "") {
		helper.setColor(Qt::green); // ensure message is green
		helper.printCenteredMsg(msg, painter, 0);
		msgTracker++;
		if (msgTracker == 50) {
			msgTracker = 0;
			msg = "";
		}
		updateHelperColorBasedOnLives();
	}
}

void Game::passPlayerInfoToAttackers() {
	for (unsigned int i=0; i < attackers.size(); i++) {
		attackers[i]->updateTargetLocation(player->getRect().center());
	}
}

// This makes attackers visible, done after a certain level is reached.
// Once attackers are visible, they can shoot.
// Prior to this, attackers are invisible in the background and are harmless.
void Game::makeLeviathanVisible() {
	Attacker *a;
	for (unsigned int i=0; i < attackers.size(); i++) {
		a = dynamic_cast<Leviathan*> (attackers[i]);
		if (a != NULL)
			attackers[i]->setVisible(true);
	}
}

void Game::makeTerrierVisible() {
	Attacker *a;
	for (unsigned int i=0; i < attackers.size(); i++) {
		a = dynamic_cast<Terrier*> (attackers[i]);
		if (a != NULL)
			attackers[i]->setVisible(true);
	}
}

void Game::makeMothershipVisible() {
	Attacker *a;
	for (unsigned int i=0; i < attackers.size(); i++) {
		a = dynamic_cast<Mothership*> (attackers[i]);
		if (a != NULL)
			attackers[i]->setVisible(true);
	}
	mothershipArrivalSound.play();
}

void Game::clearFallingObjects() {
	// delete asteroids
	for (unsigned int i=0; i<asteroids.size(); i++) {
		delete asteroids[i];
		asteroids[i] = NULL;
	}
	asteroids.clear();
	// delete items
	for (unsigned int i=0; i<items.size(); i++) {
		delete items[i];
		items[i] = NULL;
	}
	items.clear();
	// delete attackers
	for (unsigned int i=0; i<attackers.size(); i++) {
		delete attackers[i];
		attackers[i] = NULL;
	}
	attackers.clear();
}
