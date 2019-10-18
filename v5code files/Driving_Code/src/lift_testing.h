#include "vex.h"

using namespace vex;

void lift()
{
  if(Controller1.ButtonL1.pressing())
  {
    Lift_left.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
    Lift_right.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
  }
}