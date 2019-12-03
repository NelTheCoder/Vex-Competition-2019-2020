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

void Driving()
{ 
  //strafing 
  //axis 4 is left joystick, axis 1 is right joystick
  //if both joysticks are right, strafe right
  if(Controller1.Axis1.value() > 25 && Controller1.Axis4.value() > 25)
  {
    Top_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Top_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  //if both joysticks are left, strafe left
  else if(Controller1.Axis1.value() < -25 && Controller1.Axis4.value() < -25)
  {
    Top_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Top_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  //if the driver isn't trying to strafe
  else
  {
    //Driving w/ joysticks. Left joystick controls left 2 wheels, Right joystick controls right 2 wheels.
    //Axis 3 is left joystick, Axis 2 is right joystick 
    Bottom_left.spin(directionType::rev, Controller1.Axis2.value(), velocityUnits::pct);
    Top_left.spin(directionType::rev, Controller1.Axis2.value(), velocityUnits::pct);
    Top_right.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
    Bottom_right.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
  }
}

void Vacuum() 
  {  //If Button L2 is pressed down
  if(Controller1.ButtonL2.pressing())
  {
  //spin vaccuum inwards
    vacuum_left.spin(directionType::fwd, 40 , percentUnits::pct);
    vacuum_right.spin(directionType::rev, 40 , percentUnits::pct);
  }
  //otherwise if Bu tton R2 is pressed down
  else if (Controller1.ButtonR2.pressing()) 
  {
    //shoot cubes out
    vacuum_left.spin(directionType::rev, 40, percentUnits::pct);
    vacuum_right.spin(directionType::fwd, 40, percentUnits::pct);
  }
  //if you are not attempting to move the motors (pressing Button L2/R2)
  else 
  {
    //hold motor position
    vacuum_left.stop(brakeType::hold);
    vacuum_right.stop(brakeType::hold);
  }
}