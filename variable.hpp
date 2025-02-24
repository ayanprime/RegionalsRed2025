#pragma once
#include "main.h"

// ===================== Variables ===================== //

// wall-stake position
extern int wallStakePosition;

// side selection
extern char side;

// p-control variables
extern float PR;
extern float PL;
extern float RKp;
extern float LKp;
extern float etR;
extern float etL;
extern float odomR;
extern float odomL;

// timer variables
extern float startTime;
extern float endTime;
extern bool stop;
