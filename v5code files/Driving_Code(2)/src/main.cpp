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
// claw                 motor         20              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include "driving_functions.h"

using namespace vex;

int main() {
  Brain.Screen.print("sksksksksk and i oop");
  Brain.Screen.print("sksksksksk and i oop 2");
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true)
  {
    Lift_left.setMaxTorque(70, percentUnits::pct);
    Lift_right.setMaxTorque(70, percentUnits::pct);
    Drive();
    Lift();
    Controller1.ButtonR2.pressed(Claw);
    Brain.Screen.clearLine();
    Brain.Screen.print((Lift_left.rotation(rotationUnits::deg) + Lift_right.rotation(rotationUnits::deg)) / 2);
  }
}