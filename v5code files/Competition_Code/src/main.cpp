/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\neiln                                            */
/*    Created:      Sat Oct 19 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Top_left             motor         14              
// Bottom_left          motor         12              
// Top_right            motor         13              
// Bottom_right         motor         11              
// Lift_left            motor         1               
// Lift_right           motor         2               
// Lift_extra           motor         3               
// claw                 motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Competition_Commands.h"

using namespace vex;

competition Competition;

void pre_auton(void) 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

void autonomous(void) 
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
      righty(90);
      task::sleep(100);
    }
    else if(Controller1.ButtonLeft.pressing())
    {
      lefty(90);
      task::sleep(100);
    }
    else if(Controller1.ButtonDown.pressing())
    {
      backwardy(360);
      task::sleep(100);
    }
  }
}
void usercontrol(void) 
{
  while (true) 
  {
    Drive();
    Lift();
    Claw();
    wait(20, msec);
  }
}

int main() 
{
  // Set up callbacks for autonomous and driver control periods.
  
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
