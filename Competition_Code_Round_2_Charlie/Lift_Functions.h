
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\25krugercharles                                  */
/*    Created:      Mon Nov 04 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
 
using namespace vex;

double lift_speed = 40; //change the  speed of the motors overall

void Lift()
{
  if(Controller1.ButtonR1.pressing()) //this is for going up
  {
    Lift_left.setMaxTorque(75, percentUnits::pct); //can change the torque for up
    Lift_right.setMaxTorque(75, percentUnits::pct);
    if (((Lift_left.rotation(rotationUnits::deg) + Lift_right.rotation(rotationUnits::deg)) / 2) < 750)
    {
      Lift_left.spin(directionType::fwd, lift_speed, velocityUnits::pct);
      Lift_right.spin(directionType::fwd, lift_speed, velocityUnits::pct);
    }
    else 
    {
      Lift_left.stop(brakeType::hold);
      Lift_right.stop(brakeType::hold); 
    }
  }
  else if(Controller1.ButtonL1.pressing()) //this is for going down
  {
    Lift_left.setMaxTorque(70, percentUnits::pct); //can change the torque for down
    Lift_right.setMaxTorque(70, percentUnits::pct);
    Lift_left.spin(directionType::rev, lift_speed, velocityUnits::pct);
    Lift_right.spin(directionType::rev, lift_speed, velocityUnits::pct);
  }
  else if(Controller1.ButtonLeft.pressing())
  {
    Lift_left.spin(directionType::rev, lift_speed, percentUnits::pct);
    Lift_right.stop();
  }
  else if(Controller1.ButtonRight.pressing())
  {
    Lift_right.spin(directionType::rev, lift_speed, percentUnits::pct);
    Lift_left.stop();
  }
  else
  {
    Lift_left.stop(brakeType::hold);
    Lift_right.stop(brakeType::hold);
  }
}