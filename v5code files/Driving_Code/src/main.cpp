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
// Top_left             motor         11              
// Bottom_left          motor         12              
// Top_right            motor         13              
// Bottom_right         motor         14              
// Lift_left            motor         1               
// Lift_right           motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void drive()
{   
  if(Controller1.Axis1.value() > 10 && Controller1.Axis4.value() > 10)
  {
      Top_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Bottom_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Top_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Bottom_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  else if(Controller1.Axis1.value() < -10 && Controller1.Axis4.value() < -10)
  {
      Top_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Bottom_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Top_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Bottom_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  else
  {
  Bottom_left.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
  Top_left.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
  Top_right.spin(directionType::fwd, Controller1.Axis2.value() * -1, velocityUnits::pct);
  Bottom_right.spin(directionType::fwd, Controller1.Axis2.value() * -1, velocityUnits::pct);
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true)
  {
    drive();
  }
}
  
