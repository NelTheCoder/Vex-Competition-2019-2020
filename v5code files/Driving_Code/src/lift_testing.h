#include "vex.h"

using namespace vex;

void lift()
{
  Lift_left.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
  Lift_right.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct);
}