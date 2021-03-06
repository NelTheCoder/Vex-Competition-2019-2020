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

double torque_value = 70;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  /*OG AUTONOMOUS
  //go backwards
  Top_left.startRotateFor(directionType::fwd, 500, rotationUnits::deg);
  Bottom_left.startRotateFor(directionType::fwd, 500, rotationUnits::deg);
  Top_right.startRotateFor(directionType::rev, 500, rotationUnits::deg);
  Bottom_right.rotateFor(directionType::rev, 500, rotationUnits::deg);
  //open lift 
  Lift_left.startRotateFor(directionType::fwd, 360, rotationUnits::deg);
  Lift_right.startRotateFor(directionType::fwd, 360, rotationUnits::deg);
  //go back forwards
  Top_left.startRotateFor(directionType::rev, 500, rotationUnits::deg);
  Bottom_left.startRotateFor(directionType::rev, 500, rotationUnits::deg);
  Top_right.startRotateFor(directionType::fwd, 500, rotationUnits::deg);
  Bottom_right.rotateFor(directionType::fwd, 500, rotationUnits::deg);
  */
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    Drive();
    Lift();
    Controller1.ButtonR2.pressed(Claw_Open);
    Controller1.ButtonL2.pressed(Claw_Close);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
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