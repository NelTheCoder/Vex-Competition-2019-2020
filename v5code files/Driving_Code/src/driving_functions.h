#include "vex.h"

using namespace vex;

bool claw_open;

double lift_values = 35;

void open_claw()
{
  claw_open = true;
}

void close_claw()
{
  claw_open = false;
}

void CheckBatteryCapacity()
{
  Brain.Screen.clearLine();
  task::sleep(15);
  Brain.Screen.newLine();
  Brain.Screen.print(BatteryCapacity);
}

void Claw()
{
  Controller1.ButtonR2.pressed(open_claw);
  Controller1.ButtonL2.pressed(close_claw);
  if(claw_open)
  {
    claw.spin(directionType::rev, 100, velocityUnits::pct);
  }
  else if(!claw_open)
  {
    claw.spin(directionType::fwd, 100, velocityUnits::pct);
  }
  task::sleep(500);//edit this value; this is very trial & error
  claw.stop();
}
void Lift()
{
  if(Controller1.ButtonR1.pressing())
  {
    //move lift up
    Lift_left.spin(directionType::fwd, lift_values, velocityUnits::pct);
    Lift_right.spin(directionType::fwd, lift_values, velocityUnits::pct);
    Lift_extra.spin(directionType::fwd, lift_values, velocityUnits::pct);
  }
  else if(Controller1.ButtonL1.pressing())
  {
    //move lift down
    Lift_left.spin(directionType::rev, lift_values, velocityUnits::pct);
    Lift_right.spin(directionType::rev, lift_values, velocityUnits::pct);
    Lift_extra.spin(directionType::rev, lift_values, velocityUnits::pct);
  }
  else
  {
    //stahp all lift motors 
    Lift_left.stop();
    Lift_extra.stop();
    Lift_right.stop();
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
    Top_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Top_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  //if both joysticks are left, strafe left
  else if(Controller1.Axis1.value() < -10 && Controller1.Axis4.value() < -10)
  {
    Top_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Top_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
    Bottom_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  //if the driver isn't trying to strafe
  else
  {
    //Driving w/ joysticks. Left joystick controls left 2 wheels, Right joystick controls right 2 wheels.
    //Axis 3 is left joystick, Axis 2 is right joystick
    Bottom_left.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
    Top_left.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
    Top_right.spin(directionType::rev, Controller1.Axis2.value(), velocityUnits::pct);
    Bottom_right.spin(directionType::rev, Controller1.Axis2.value(), velocityUnits::pct);
  }
}