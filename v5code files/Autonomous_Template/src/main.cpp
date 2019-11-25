/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\neiln                                            */
/*    Created:      Thu Nov 14 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Top_left             motor         11              
// Bottom_left          motor         13              
// Top_right            motor         12              
// Bottom_right         motor         14              
// Lift_left            motor         1               
// Lift_right           motor         2               
// claw                 motor         20              
// vacuum_left          motor         3               
// vacuum_right         motor         4               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool alignedWithCube = false;

//bot is ~ 44.3 cm 

//12.59 inches in one rotation

void Autonomous()
{
  Top_left.startRotateFor(directionType::fwd, 360, rotationUnits::deg);
  Bottom_left.startRotateFor(directionType::fwd,360, rotationUnits::deg);
  Top_right.startRotateFor(directionType::rev, 360, rotationUnits::deg);
  Bottom_right.rotateFor(directionType::rev, 360, rotationUnits::deg);

  Top_left.startRotateFor(directionType::rev, 360, rotationUnits::deg);
  Bottom_left.startRotateFor(directionType::rev,360, rotationUnits::deg);
  Top_right.startRotateFor(directionType::fwd, 360, rotationUnits::deg);
  Bottom_right.rotateFor(directionType::fwd, 360, rotationUnits::deg);
}
int main()
{
  //stuff
  while(true)
  {
    Controller1.ButtonL1.pressed(Autonomous);
  }
}