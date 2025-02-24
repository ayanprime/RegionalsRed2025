#include "main.h"

void forwardP(float Dis) {
    //distance right pod has gone
    odomR = RightP.position(turns) * 8.63937;
    //distance left pod has gone
    odomL = LeftP.position(turns) * 8.63937;
    
    dis = Dis;

    etR = (Dis - odomR);
    etL = (Dis - odomL);

    PR = RKp * etR;
    PL = LKp * etL;
  
    Right.setVelocity(PR, percent);
    Left.setVelocity(PL, percent);
    Right.spin(forward);
    Left.spin(forward);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(RightP.position(turns) * 8.63937);
    Brain.Screen.print(" ");
    Brain.Screen.print(LeftP.position(turns) * 8.63937);

}

void turnP (float angle) {

    //distance right pod has gone
    odomR = RightP.position(turns) * 8.63937;
    //distance left pod has gone
    odomL = LeftP.position(turns) * 8.63937;

    disR = angR * angle;
    disL = angL * angle * -1;

    

}

// can help robot go straight to point while turning, resulting in a curve WARNING LOTS OF BUGS IN THIS FUNCTION
// USE THE OTHER TWO FOR NOW
void goP(float x, float y, float angle, char dir) {

    // WHEN PLUGGING IN X AND Y, ALWAYS MEASURE Y FROM FRONT OF ROBOT, AND X FROM SIDE CLOSEST TO DESTINATION
    // center to pod offset distance is 4.0625 inches
    // side to pod offset distance is 4.3125 inches
    // pod to front offset distance is 10.5 inches

    //distance right pod has gone
    odomR = RightP.position(turns) * 8.63937;
    //distance left pod has gone
    odomL = LeftP.position(turns) * 8.63937;

    double shortX = x + 4.3125 - 10.5;
    double shortY = y + 10.5 - 4.0625;
    double longX = x + 4.3125 + (2 * 4.0625) - 10.5;
    double longY = y + 10.5 + 4.0625;
    double shortH = ((shortX - shortY) * (shortX - shortY)) / ((shortX + shortY) * (shortX + shortY));
    double longH = ((longX - longY) * (longX - longY)) / ((longX + longY) * (longX + longY));
    double shortSide = pi * (shortX + shortY) * (1 + ((3 * shortH) / (10 + sqrt(4 - (3 * shortH)))));
    double longSide = pi * (longX + longY) * (1 + ((3 * longH) / (10 + sqrt(4 - (3 * longH)))));
    double shortDis = shortSide * (angle / 360);
    double longDis = longSide * (angle / 360);
    
    if (dir == 'R') {

        etR = (shortDis - odomR);
        etL = (longDis - odomL);

    } else if (dir == 'L') {

        etR = (longDis - odomR);
        etL = (shortDis - odomL);

    }

    PR = RKp * etR;
    PL = LKp * etL;

    Right.setVelocity(PR, percent);
    Left.setVelocity(PL, percent);
    Right.spin(forward);
    Left.spin(forward);
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(RightP.position(turns) * 8.63937);
    Brain.Screen.print(" ");
    Brain.Screen.print(LeftP.position(turns) * 8.63937);

}
