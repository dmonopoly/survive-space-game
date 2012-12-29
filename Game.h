#ifndef GAME_H_
#define GAME_H_

#include <vector>

#include "ScreenHelper.h"
#include "Object.h"
#include "FallingObject.h"
#include "Player.h"
#include "Asteroid.h"
#include "Item.h"
#include "Attacker.h"
#include "Leviathan.h"
#include "Terrier.h"
#include "Mothership.h"
#include "EnergyBall1.h"
#include "EnergyBall2.h"
#include "EnergyBall3.h"
#include "EnergyBallLife.h"

#include <QSound>
#include <QWidget>
#include <QKeyEvent>

// 4 possible states of the game
// main menu - preparation screen right before a game starts
// game on - game in progress
// game over - player has lost, score shown
// paused - game is paused
enum GameState { MAIN_MENU, GAME_ON, GAME_OVER, PAUSED };

class Game: public QWidget {

    Q_OBJECT // Qt automatically replaces this with its own dark magic

public:
    Game(QWidget *parent = 0);
    ~Game();

private slots:
	// Required methods - these are slots
	void paintEvent(QPaintEvent *event); // painter here
	void timerEvent(QTimerEvent *event);
	void keyPressEvent(QKeyEvent *event);
//	void keyReleaseEvent(QKeyEvent *event); for future version

private:
	const static std::string BACKGROUND1;
	const static std::string BACKGROUND2;
	const static std::string BACKGROUND3;

	QPalette palette; // for background stuff
    ScreenHelper helper;
    int lives;
    long int score;
    int level; // 1 is easiest and what you start at; higher numbers are faster
    int mainTimerLevel; // stores mainTimerId's interval in milliseconds (the value in startTimer(_) )
    int mainTimerId;
    int asteroidTimerId;
    GameState state;
    bool justLostLife;
    std::string msg;
    int msgTracker; // to keep track of how long message should stay, based on mainTimerLevel
    int invCount; // invincible count; when zero, player is not invincible; when >0, detectCollisions does not check for collisions; counts down

    // Objects
    std::vector<Asteroid *> asteroids;
    std::vector<Item *> items;
    std::vector<Attacker *> attackers;

    Player *player;

    // Methods that correspond to a state
    void mainMenu(QPainter &);
    void continueGame(QPainter &);
    void gameOver(QPainter &);

    // Processing methods
    void drawObjects(QPainter &); // within continueGame
    void setFallingObjectsOn(bool);
    void setFallingObjectsTimerLevel(int);
    void speedUpFallingObjects();
    void passPlayerInfoToAttackers();
    void makeLeviathanVisible();
    void makeTerrierVisible();
    void makeMothershipVisible();

    void processSpaceKey();
	void dealWithPause();
	void detectCollisions();

	void preparePlayer(); // called in prepareObjects, and elsewhere too
	void prepareObjects();

	void respondToItem(Item *);

	void loseLife(QPainter &);

	void levelCheck();
	void messageCheck(QPainter &);

	void updateScoreDisplay(QPainter &);
	void startGame();
	void resetGame();
	void updateHelperColorBasedOnLives();

	void clearFallingObjects();
};

#endif /* GAME_H_ */
