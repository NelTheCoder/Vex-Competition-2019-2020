#include "vex.h"

using namespace vex;

double controlboi = 541;

//turn left
void lefty(double amount)
{
    //make command usable with human degrees
    amount = amount * (controlboi/90);
    Top_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Top_right.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, true);
}
//move backwards
void backwardy(double amount)
{
    Top_left.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Top_right.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_right.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
}
//turn right
void righty(double amount)
{
    //make command usable with human degrees
    amount = amount * (controlboi/90);
    Top_left.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Top_right.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_right.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
}
//move forward
void forwardy(double amount)
{
    Top_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Top_right.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_right.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
}
void victory_dance()
{
    Top_left.startRotateFor(720,rotationUnits::deg,100,velocityUnits::pct);
    Bottom_left.startRotateFor(720,rotationUnits::deg,100,velocityUnits::pct);
    Top_right.startRotateFor(-720,rotationUnits::deg,100,velocityUnits::pct);
    Bottom_right.startRotateFor(-720,rotationUnits::deg,100,velocityUnits::pct);
    Brain.Screen.print("V-I-C-T-O-R-Y--D-A-N-C-E");
}