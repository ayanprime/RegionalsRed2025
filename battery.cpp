#include "main.h"

void battery (void) {

    Brain.Screen.setFillColor(white);
    Brain.Screen.drawRectangle(75, 80, 20, 80);
    // to 100%
    if (Brain.Battery.capacity() > 90) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(100, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(100, 20, 20, 200);

    }
    // to 90%
    if (Brain.Battery.capacity() > 80) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(125, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(125, 20, 20, 200);

    }
    // to 80%
    if (Brain.Battery.capacity() > 70) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(150, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(150, 20, 20, 200);

    }
    // to 70%
    if (Brain.Battery.capacity() > 60) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(175, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(175, 20, 20, 200);

    }

    // to 60%
    if (Brain.Battery.capacity() > 50) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(200, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(200, 20, 20, 200);

    }

    // to 50%
    if (Brain.Battery.capacity() > 40) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(225, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(225, 20, 20, 200);

    }

    // to 40%
    if (Brain.Battery.capacity() > 30) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(250, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(250, 20, 20, 200);

    }

    // to 30%
    if (Brain.Battery.capacity() > 20) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(275, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(275, 20, 20, 200);

    }

    // to 20%
    if (Brain.Battery.capacity() > 10) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(300, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(300, 20, 20, 200);

    }

    // to 10%
    if (Brain.Battery.capacity() > 1) {

        Brain.Screen.setFillColor(yellow);
        Brain.Screen.drawRectangle(325, 20, 20, 200);

    } else {

        Brain.Screen.setFillColor(black);
        Brain.Screen.drawRectangle(325, 20, 20, 200);

    }
}
