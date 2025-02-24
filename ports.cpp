#include "main.h"

// ===================== Devices ===================== //

// main devices
brain Brain;
controller controller1 = controller(primary);

//conveyor
motor conveyor = motor(PORT2, ratio6_1, false);

//intake
motor intake = motor(PORT1, ratio18_1, true);

//wall-stake scorer
motor leftWallStake = motor(PORT18, ratio36_1, false);
motor rightWallStake = motor(PORT8, ratio36_1, true);

//drive-train
motor LF = motor(PORT13, ratio18_1, false);
motor LB = motor(PORT9, ratio18_1, false);
motor_group LeftDrive(LF, LB);

motor RF = motor(PORT10, ratio18_1, true);
motor RB = motor(PORT15, ratio18_1, true);
motor_group RightDrive(RF, RB);

//pods
rotation leftPod = rotation(PORT12, true);
rotation rightPod = rotation(PORT11, false);

//sorter
optical sorter = optical(PORT19);

//clamp
digital_out clamp = digital_out(Brain.ThreeWirePort.F);

//selector
pot selector = pot(Brain.ThreeWirePort.A);
