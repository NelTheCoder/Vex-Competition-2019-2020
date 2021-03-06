/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\neiln                                            */
/*    Created:      Mon Nov 04 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision               vision        10              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

event checkRed = event();
event checkBlue = event();
event checkGreen = event();

void hasPurpleCallback() {
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(1, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(1, 1);
  Vision.takeSnapshot(Vision__PURPLE_CUBE);
  if (Vision.objectCount > 0) {
    Brain.Screen.print("Purple Cube Found");
  } else {
    Brain.Screen.print("No Purple Cube");
  }
}

void hasOrangeCallback() {
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(3, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(3, 1);
  Vision.takeSnapshot(Vision__ORANGE_CUBE);
  if (Vision.objectCount > 0) {
    Brain.Screen.print("Orange Cube Found");
  } else {
    Brain.Screen.print("No Orange Cube");
  }
}

void hasGreenCallback() {
  Brain.Screen.setFont(mono40);
  Brain.Screen.clearLine(5, black);
  Brain.Screen.setCursor(Brain.Screen.row(), 1);
  Brain.Screen.setCursor(5, 1);
  Vision.takeSnapshot(Vision__GREEN_CUBE);
  if (Vision.objectCount > 0) {
    Brain.Screen.print("Green Cube Found");
  } else {
    Brain.Screen.print("No Green Cube");
  }
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  checkBlue(hasPurpleCallback);
  checkRed(hasOrangeCallback);
  checkGreen(hasGreenCallback);
  
  while (true) {
    checkBlue.broadcastAndWait();
    checkRed.broadcastAndWait();
    checkGreen.broadcastAndWait();
    wait(1, seconds);
  }
}
