#include "main.h"

// ===================== Variables ===================== //

// wall-stake position
int wallStakePosition = 0;

// side selection
char side;

// p-control variables
float PR;
float PL;
float RKp = 1.5;
float LKp = 1.5;
float etR;
float etL;
float odomR;
float odomL;

// timer variables
float startTime;
float endTime;
bool stop = false;
