/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\25krugercharles                                  */
/*    Created:      Mon Nov 04 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Top_left             motor         11              
// Bottom_left          motor         13              
// Top_right            motor         12              
// Bottom_right         motor         14              
// Lift_left            motor         1               
// Lift_right           motor         2               
// claw                 motor         19              
// vacuum_left          motor         3               
// vacuum_right         motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "Lift_Functions.h"
#include "claw_functions.h"
#include "vacuum_spinnys.h"
#include "Driving_Functions.h"
#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Make sure the screen on the controller is blank before proceding to print
  // to the screen
  Controller1.Screen.clearScreen();

  // Set the cursor (text starting point) to row 1, column 1
  Controller1.Screen.setCursor(1, 1);

  // Print "HELLO!" on the first line
  Controller1.Screen.print("HELLO!");

  // Move the cursor to the next line then print
  Controller1.Screen.newLine();
  Controller1.Screen.print("(suspiciously sentient bot)");

  // Wait 1 second
  task::sleep(1000);
  // Brain.Screen.print("You were expecting Charlie, but it was I, DIO");
  // Brain.Screen.newLine();
  // Brain.Screen.print("");
  while (true) {
    //failsafe
    if (Controller1.ButtonLeft.pressing() && Controller1.ButtonA.pressing()) {
      // all motors stop
      Top_left.stop();
      Top_right.stop();
      Bottom_left.stop();
      Bottom_right.stop();
      Lift_left.stop();
      Lift_right.stop();
      claw.stop();

      task::sleep(999); // the motors wait 1 second

      // the motors run for a little bit then you can control it again
      Top_left.spin(fwd, 10, velocityUnits::pct);
      Top_right.spin(fwd, 10, velocityUnits::pct);
      Bottom_left.spin(fwd, 10, velocityUnits::pct);
      Bottom_right.spin(fwd, 10, velocityUnits::pct);
      Lift_left.spin(fwd, 10, velocityUnits::pct);
      Lift_right.spin(fwd, 10, velocityUnits::pct);
      claw.spin(fwd, 10, velocityUnits::pct);

      // this is the failsafe, when you click the up arrow and the A button all
      // motors stop, you wait one second, then the motors run for a litle bit
      // and then you have control again
    }
    else
    {
      Drive();
      Controller1.ButtonR2.pressed(ClawOpenorClose);
      Lift();
    }
  }
}