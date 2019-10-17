/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\neiln                                            */
/*    Created:      Wed Oct 16 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Bottom_left          motor         12              
// Bottom_right         motor         11              
// Top_right            motor         13              
// Top_left             motor         14              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

/*
Set the motors to the correct ports
*/
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
void autonomous()
{
    lefty(20);
    forwardy(360);
    righty(105);
    forwardy(720);
    lefty(45);
    forwardy(360);
    righty(75);
    forwardy(1080);
    victory_dance();
}
int main() 
{
    while(true)
    {
        Controller1.ButtonL1.pressed(autonomous);
        if(Controller1.ButtonUp.pressing())
        {
            forwardy(360);
            task::sleep(100);
        }
        else if(Controller1.ButtonRight.pressing())
        {
            righty(541);
            task::sleep(100);
        }
        else if(Controller1.ButtonLeft.pressing())
        {
            lefty(360);
            task::sleep(100);
        }
        else if(Controller1.ButtonDown.pressing())
        {
            backwardy(360);
            task::sleep(100);
        }
    }
}

