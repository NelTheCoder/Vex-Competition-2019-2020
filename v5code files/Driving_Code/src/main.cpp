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
// Top_left             motor         14              
// Bottom_left          motor         12              
// Top_right            motor         13              
// Bottom_right         motor         11              
// Lift_left            motor         1               
// Lift_right           motor         2               
// claw                 motor         15              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include "driving_functions.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true)
  {
    Lift_left.setMaxTorque(75, percentUnits::pct);
    Lift_right.setMaxTorque(75, percentUnits::pct);
    //Drive();
    Lift();
    Controller1.ButtonR2.pressed(Claw);
  }
}