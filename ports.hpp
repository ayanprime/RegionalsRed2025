#pragma once
#include "main.h"

// ===================== Devices ===================== //

// main devices
extern brain Brain;
extern controller controller1;

//conveyor
extern motor conveyor;

//intake
extern motor intake;

//wall-stake scorer
extern motor leftWallStake;
extern motor rightWallStake;

//drive-train
extern motor LF;
extern motor LB;        
extern motor_group LeftDrive;

extern motor RF;
extern motor RB;
extern motor_group RightDrive;

//pods
extern rotation leftPod;
extern rotation rightPod;

//sorter
extern optical sorter;

//clamp
extern digital_out clamp;

//selector
extern pot selector;
