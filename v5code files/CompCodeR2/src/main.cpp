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
// Left_pot             pot           B               
// Right_pot            pot           A               
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
  //turn 90 leftZ
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

  //move forward
  Left_motor.rotateFor(directionType::rev, 100, rotationUnits::deg);
  Right_motor.rotateFor(directionType::fwd, 100, rotationUnits::deg);

  //open claw
  claw.rotateFor(directionType::fwd, 70, rotationUnits::deg);

  //lift - up
  Lift_left.rotateFor(directionType::fwd, 70, rotationUnits::deg);
  Lift_right.rotateFor(directionType::fwd, 70, rotationUnits::deg);

  //move forward
  Left_motor.rotateFor(directionType::rev, 15, rotationUnits::deg);
  Right_motor.rotateFor(directionType::fwd, 15, rotationUnits::deg);

  //close claw
  claw.rotateFor(directionType::rev, 60, rotationUnits::deg);

  //move backward
  Left_motor.rotateFor(directionType::fwd, 115, rotationUnits::deg);
  Right_motor.rotateFor(directionType::rev, 115, rotationUnits::deg);

  //turn left
  Left_motor.rotateFor(directionType::fwd, 180, rotationUnits::deg);
  Right_motor.rotateFor(directionType::fwd, 180, rotationUnits::deg);

  //move forward
  Left_motor.rotateFor(directionType::rev, 200, rotationUnits::deg);
  Right_motor.rotateFor(directionType::fwd, 200, rotationUnits::deg);

  //lift - down
  Lift_left.rotateFor(directionType::rev, 65, rotationUnits::deg);
  Lift_right.rotateFor(directionType::rev, 65, rotationUnits::deg);

  //open claw
  claw.rotateFor(directionType::fwd, 50, rotationUnits::deg);

  //move backward
  Left_motor.rotateFor(directionType::fwd, 115, rotationUnits::deg);
  Right_motor.rotateFor(directionType::rev, 115, rotationUnits::deg);
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
  while (true) {
    if (Controller1.ButtonLeft.pressing() && Controller1.ButtonA.pressing()) {
      // all motors stop
      Top_left.stop();
      Top_right.stop();
      Bottom_left.stop();
      Bottom_right.stop();
      Lift_left.stop();
      Lift_right.stop();
      claw.stop();

      task::sleep(999); // the motors wait less then one second

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
      /*if(Right_pot.value(rotationUnits::deg) - Left_pot.value(rotationUnits::deg) > 5)
      {
        Lift_left.startRotateFor(directionType::fwd, 1, rotationUnits::deg);
      }
      else if(Right_pot.value(rotationUnits::deg) - Left_pot.value(rotationUnits::deg) < -4)
      {
        Lift_right.startRotateFor(directionType::fwd, 1, rotationUnits::deg);
      }
      else 
      {
        return;
      }*/
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  claw.startRotateFor(directionType::rev, 170, rotationUnits::deg);
  Controller1.Screen.print("godd howard");
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