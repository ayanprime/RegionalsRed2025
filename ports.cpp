#include "main.h"

// ===================== Devices ===================== //

//main devices
brain Brain;
controller controller1 = controller(primary);

//motors
motor rmA = motor(PORT9, ratio18_1, true);
motor rmB = motor(PORT10, ratio18_1, true);
motor_group Right = motor_group(rmA, rmB);

motor lmA = motor(PORT17, ratio18_1, false);
motor lmB = motor(PORT18, ratio18_1, false);
motor_group Left = motor_group(lmA, lmB);

//pods
rotation RightP = rotation(PORT8, false);

rotation LeftP = rotation(PORT20, true);

//intake
motor intake = motor(PORT6, ratio18_1, true);

//conveyor
motor conveyor = motor(PORT11, ratio18_1, true);

//clamp
digital_out latch = digital_out(Brain.ThreeWirePort.H);
