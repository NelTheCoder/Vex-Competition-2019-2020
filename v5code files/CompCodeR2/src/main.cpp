/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
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
// claw                 motor         19              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Lift_Functions.h"
#include "claw_functions.h"
#include "Driving_Functions.h"

using namespace vex;

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
  motor_group Left_motor(Top_left, Bottom_left);
  motor_group Right_motor(Top_right, Bottom_right);
  
  //set speed
  Left_motor.setVelocity(75, percentUnits::pct);
  Right_motor.setVelocity(75, percentUnits::pct);

  //go forward
  Left_motor.rotateFor(directionType::rev, 360, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::fwd, 360, rotationUnits::deg);

  //turn 90 left
  Left_motor.rotateFor(directionType::fwd, 180, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::fwd, 180, rotationUnits::deg);

  //go forward
  Left_motor.rotateFor(directionType::rev, 90, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::fwd, 90, rotationUnits::deg);

  //pick up cubes
  //https://www.nytimes.com/2019/12/07/style/its-karentown.html
  Left_motor.rotateFor(directionType::rev, 90, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::fwd, 90, rotationUnits::deg);

  claw.rotateFor(directionType::rev, 95, rotationUnits::deg);

  Lift_left.startRotateFor(directionType::fwd, 25, rotationUnits::deg);
  Lift_right.rotateFor(directionType::fwd, 25, rotationUnits::deg);

  //go backwards
  Left_motor.rotateFor(directionType::rev, 90, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::fwd, 90, rotationUnits::deg);

  //turn 90 right
  Left_motor.rotateFor(directionType::rev, 180, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::rev, 180, rotationUnits::deg);

  //go backwards
  Left_motor.rotateFor(directionType::rev, 360, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::fwd, 360, rotationUnits::deg);

  //turn 90 right
  Left_motor.rotateFor(directionType::rev, 360, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::rev, 360, rotationUnits::deg);

  //go forwards
  Left_motor.rotateFor(directionType::rev, 360, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::fwd, 360, rotationUnits::deg);

  //drop cubes
  Lift_left.startRotateFor(directionType::rev, 25, rotationUnits::deg);
  Lift_right.rotateFor(directionType::rev, 25, rotationUnits::deg);

  claw.rotateFor(directionType::fwd, 95, rotationUnits::deg);
  //go backwards
  Left_motor.rotateFor(directionType::fwd, 360, rotationUnits::deg, false);
  Right_motor.rotateFor(directionType::rev, 360, rotationUnits::deg);
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
      Controller1.ButtonL2.pressed(Claw_Close);
      Lift();
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  claw.startRotateFor(directionType::rev, 170, rotationUnits::deg);
  Brain.Screen.print("oh noes! XVI");
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