/*CONFIG THINGS*/

#include "vex.h"

using namespace vex;

/*VARIABLES*/

double lift_speed = 35;

bool claw_open = true;

bool lift_hold_position_value_set = false;

/*FUNCTIONS*/

/*

void Hold_lift_position()
{
  if(lift_hold_position_value_set)
  {
    if(((Lift_left.rotation(rotationUnits::raw) + Lift_right.rotation(rotationUnits::raw))/2) < lift_hold_position_value)
    {
      Lift_left.spin(directionType::fwd, lift_speed, velocityUnits::pct);
      Lift_right.spin(directionType::fwd, lift_speed, velocityUnits::pct);
    }
    else
    {
      Lift_left.stop();
      Lift_right.stop();
    }
  }
}
*/

void Claw()
{
  if(claw_open)
  {
    claw.startRotateFor(directionType::rev, 180, rotationUnits::deg);
    claw_open = false;
  }
  else if(!claw_open)
  {
    claw.startRotateFor(directionType::fwd, 180, rotationUnits::deg);
    claw_open = true;
  }
}

void Lift()//leave notes neil!!!
{
  if(Controller1.ButtonR1.pressing())
  {
    if (((Lift_left.rotation(rotationUnits::deg) + Lift_right.rotation(rotationUnits::deg)) / 2) < 650)
    {
      Lift_left.spin(directionType::fwd, lift_speed, velocityUnits::pct);
      Lift_right.spin(directionType::fwd, lift_speed, velocityUnits::pct);
    }
    else 
    {
      Lift_left.stop(brakeType::hold);
      Lift_right.stop(brakeType::hold);//stoping lift 
    }
  }
  else if(Controller1.ButtonL1.pressing())
  {
    Lift_left.spin(directionType::rev, lift_speed, velocityUnits::pct);
    Lift_right.spin(directionType::rev, lift_speed, velocityUnits::pct);
  }
  else
  {
    Lift_left.stop(brakeType::hold);
    Lift_right.stop(brakeType::hold);
  }
}
//driving code
void Drive()
{   
  //strafing
  //axis 4 is left joystick, axis 1 is right joystick
  //if both joysticks are right, strafe right
  if(Controller1.Axis1.value() > 10 && Controller1.Axis4.value() > 10)
  {
    Top_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Top_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  //if both joysticks are left, strafe left
  else if(Controller1.Axis1.value() < -10 && Controller1.Axis4.value() < -10)
  {
    Top_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Top_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  //if the driver isn't trying to strafe
  else
  {
    //Driving w/ joysticks. Left joystick controls left 2 wheels, Right joystick controls right 2 wheels.
    //Axis 3 is left joystick, Axis 2 is right joystick
    Bottom_left.spin(directionType::rev, Controller1.Axis2.value(), velocityUnits::pct);
    Top_left.spin(directionType::rev, Controller1.Axis2.value(), velocityUnits::pct);
    Top_right.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
    Bottom_right.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
  }
}