/*CONFIG THINGS*/

#include "vex.h"

using namespace vex;

/*VARIABLES*/

double lift_speed = 50;

bool claw_open = true;

bool lift_hold_position_value_set = false;

/*FUNCTIONS*/


void Set_hold_lift_position()
{
  if(lift_hold_position_value_set)
  {
    lift_hold_position_value_set = false;
  }
  else
  {
    lift_hold_position_value_set = true;
  }
}

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

void Lift()
{
  if(Controller1.ButtonR1.pressing())
  {
    //move lift up
    Lift_left.spin(directionType::fwd, lift_speed, velocityUnits::pct);
    Lift_right.spin(directionType::fwd, lift_speed, velocityUnits::pct);
    /*while(Lift_left.velocity(velocityUnits::rpm) < 0 && Lift_right.velocity(velocityUnits::rpm) < 0)
    {
      Lift_left.stop();
      Lift_right.stop();
    }*/
  }
  else if(Controller1.ButtonL1.pressing())
  {
    //move lift down
    Lift_left.spin(directionType::rev, 15, velocityUnits::pct);
    Lift_right.spin(directionType::rev, 15, velocityUnits::pct);
  }
  else
  {
    //if no input; v e r y slowly go up;
    Lift_left.spin(directionType::fwd, 5, velocityUnits::pct);
    Lift_right.spin(directionType::fwd, 5, velocityUnits::pct);
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