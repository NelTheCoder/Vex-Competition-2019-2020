#include "vex.h"

using namespace vex;

void lift()
{
  /*Lift_left.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
  Lift_right.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);*/
  if(Controller1.ButtonR1.pressing())
  {
    Lift_left.spin(directionType::fwd, 100, velocityUnits::pct);
    Lift_right.spin(directionType::fwd, 100, velocityUnits::pct);
  }
  if(Controller1.ButtonL1.pressing())
  {
    Lift_left.spin(directionType::fwd, -100, velocityUnits::pct);
    Lift_right.spin(directionType::fwd, -100, velocityUnits::pct);
  }
}

void drive()
{   
  if(Controller1.Axis1.value() > 10 && Controller1.Axis4.value() > 10)
  {
      Top_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Bottom_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Top_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Bottom_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  else if(Controller1.Axis1.value() < -10 && Controller1.Axis4.value() < -10)
  {
      Top_left.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Bottom_left.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Top_right.spin(directionType::fwd, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
      Bottom_right.spin(directionType::rev, (Controller1.Axis1.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
  }
  else
  {
  Bottom_left.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
  Top_left.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
  Top_right.spin(directionType::fwd, Controller1.Axis2.value() * -1, velocityUnits::pct);
  Bottom_right.spin(directionType::fwd, Controller1.Axis2.value() * -1, velocityUnits::pct);
  }
}