#include "main.h"

// ===================== Devices ===================== //

// main devices
brain Brain;
controller controller1 = controller(primary);

//conveyor
motor conveyor = motor(PORT9, ratio6_1, false);

//intake
motor intake = motor(PORT10, ratio18_1, true);

//wall-stake scorer
motor leftWallStake = motor(PORT1, ratio18_1, false);
motor rightWallStake = motor(PORT2, ratio18_1, true);
