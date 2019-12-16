#include "vex.h"

using namespace vex;

void potentiometer()
{
  if(fabsf(Left_pot.value(rotationUnits::deg)) - fabsf(Right_pot.value(rotationUnits::deg)) > 3)
  {
    //do stuf
  }
}