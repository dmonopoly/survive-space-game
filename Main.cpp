/*
 * Main.cpp
 *
 *  Created on: Mar 30, 2012
 *      Author: David Zhang
 */

#include "Game.h"
#include <time.h> // for randomness
#include <QDesktopWidget>
#include <QApplication>


void center(QWidget &widget) {
    int x, y, screenWidth, screenHeight;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - WIDTH)/2;
    y = (screenHeight - HEIGHT)/2;

    widget.setGeometry(x, y, WIDTH, HEIGHT);
    widget.setFixedSize(WIDTH, HEIGHT);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    srand(time(NULL)); // seed time randomly only once

    // Prepare window
    Game window;
    window.setWindowTitle("My Game");
    window.show();
    center(window);

    return app.exec();
}
