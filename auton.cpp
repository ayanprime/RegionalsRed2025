#include "main.h"

// ===================== P-Control ===================== //
void goP(float DisL, float DisR) {
    //distance right pod has gone
    odomR = rightPod.position(turns) * 8.63937;
    //distance left pod has gone
    odomL = leftPod.position(turns) * 8.63937;

    //error right pod has
    etR = ((DisR - odomR) / DisR) * 100;
    //error left pod has
    etL = ((DisL - odomL) / DisL) * 100;

    //power constants should have
    if (DisR < 6 || DisL < 6) {
        RKp = 0.3;
        LKp = 0.3;
    } else {
        RKp = 1.5;
        LKp = 1.5;
    }

    //power right pod should have
    PR = RKp * etR;
    //power left pod should have
    PL = LKp * etL;

    //drive motors
    LeftDrive.setVelocity(PL, percent);
    RightDrive.setVelocity(PR, percent);
    LeftDrive.spin(forward);
    RightDrive.spin(forward);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("odomR: %f", odomR);
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("odomL: %f", odomL);

}

// ===================== Auton Routines ===================== //
void Right() {
    rightPod.setPosition(0, degrees);
    leftPod.setPosition(0, degrees);
    while (true) {
        goP(5.9, -5.9);    
    }
}
