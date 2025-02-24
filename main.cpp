/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       ayanb                                                     */
/*    Created:      2/11/2025, 9:05:06 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "main.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  while (true) {
    if (selector.angle() < 167) {
      side = 'r';
    } else if (selector.angle() > 167) {
      side = 'l';
    } else {
      Brain.Screen.clearScreen();
    }
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  Right();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  Brain.Screen.clearScreen();
  drawLogo();
  leftWallStake.setPosition(0, degrees);
  rightWallStake.setPosition(0, degrees);
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    battery();
    sorter.setLightPower(100, percent);
    LeftDrive.setVelocity(controller1.Axis3.position()+controller1.Axis1.position(), percent);
    RightDrive.setVelocity(controller1.Axis3.position()-controller1.Axis1.position(), percent);
    leftWallStake.setVelocity(50, percent);
    rightWallStake.setVelocity(50, percent);
    leftWallStake.setStopping(hold);
    rightWallStake.setStopping(hold);
    LeftDrive.spin(forward);
    RightDrive.spin(forward);
    conveyor.setVelocity(40, percent);


    // conveyor and intake

    if(controller1.ButtonR1.pressing()) {
      conveyor.spin(forward);
      intake.spin(forward, 100, percent);
    } else if(controller1.ButtonR2.pressing()) {
      conveyor.spin(reverse);
      intake.spin(reverse, 100, percent);
    } else {
      conveyor.stop();
      intake.stop();
    }
    
    if (sorter.hue() <= 240 && sorter.hue() >= 212) {
      conveyor.setVelocity(-100, percent);
    } 

    // wall-stake control

    if(controller1.ButtonB.pressing()) {
      wallStakePosition = 0;
    } else if(controller1.ButtonA.pressing()) {
      wallStakePosition = 1;
    } else if(controller1.ButtonX.pressing()) {
      wallStakePosition = 2;
    }

    // wall-stake position

    if(wallStakePosition == 0) {
      leftWallStake.setVelocity(35, percent);
      rightWallStake.setVelocity(35, percent);
      leftWallStake.spinToPosition(0, degrees, false);
      rightWallStake.spinToPosition(0, degrees, false);
    } else if(wallStakePosition == 1) {
      leftWallStake.setVelocity(50, percent);
      rightWallStake.setVelocity(50, percent);
      leftWallStake.spinToPosition(24, degrees, false);
      rightWallStake.spinToPosition(24, degrees, false);
    } else if(wallStakePosition == 2) {
      leftWallStake.setVelocity(100, percent);
      rightWallStake.setVelocity(100, percent);
      leftWallStake.spinToPosition(130, degrees, false);
      rightWallStake.spinToPosition(130, degrees, false);
    }

    if(controller1.ButtonDown.pressing()) {
      clamp.set(true);
    } else if(controller1.ButtonUp.pressing()) {
      clamp.set(false);
    }

    wait(1, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
