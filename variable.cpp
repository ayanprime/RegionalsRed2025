#include "variable.hpp" // Only include variable.hpp, no main.h

// make a timer
vex::timer myTimer;
double dt = 0.0;
double odomR = 0.0;
double odomL = 0.0;
double etR = 0.0;
double etL = 0.0;
double RKp = 2.5; //Right proportional constant
double LKp = 2.5; //Left proportional constant
double dis = 0.0; //distance both pods have to go if they are equal to eachother
double disR = 0.0; //distance right pod has to go
double disL = 0.0; //distance left pod has to go
double angR = 0.0; //right distance per angle of degree of turn
double angL = 0.06222222222; //left distance per angle degree of turn
double IoR = 0.0; // integral constant right pod
double IoL = 0.0; // integral contant left pod
int elapsedTime = myTimer.time(vex::timeUnits (msec));
float Ki = 4.0; 
double PR = 0.0; // proportional right pod
double PL = 0.0; // proportional left pod
double IR = 0.0; // integral right pod
double IL = 0.0; // integral left pod
double pi = M_PI; // pi
//movement starters and finishers for PID
bool check = false;
bool moveone = true;
bool movetwo = false;
bool movethree = false;
bool movefour = false;
// auton select & driver select
bool R = false;
bool L = false;
bool Ayan = true;
bool Bennett = false;
bool Max = false;
