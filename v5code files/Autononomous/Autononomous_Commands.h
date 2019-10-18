#include "vex.h"

using namespace vex;

void lefty(double amount)
{
    Top_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Top_right.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, true);
}
void backwardy(double amount)
{
    Top_left.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Top_right.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, true);
}
void righty(double amount)
{
    Top_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Top_right.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, true);
}
void forwardy(double amount)
{
    Top_left.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_left.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Top_right.rotateFor(amount, rotationUnits::deg, 100, velocityUnits::pct, false);
    Bottom_right.rotateFor(-amount, rotationUnits::deg, 100, velocityUnits::pct, true);
}
void victory_dance()
{
    Top_left.startRotateFor(720,rotationUnits::deg,100,velocityUnits::pct);
    Bottom_left.startRotateFor(720,rotationUnits::deg,100,velocityUnits::pct);
    Top_right.startRotateFor(720,rotationUnits::deg,100,velocityUnits::pct);
    Bottom_right.startRotateFor(720,rotationUnits::deg,100,velocityUnits::pct);
    Brain.Screen.print("V-I-C-T-O-R-Y--D-A-N-C-E");
}