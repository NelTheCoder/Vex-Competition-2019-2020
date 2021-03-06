/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\25krugercharles                                  */
/*    Created:      Mon Nov 04 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

double claw_value = 200;
 
using namespace vex;

bool claw_status = false;

void example()
{
  if(claw_status)
  {
    claw.startRotateFor(directionType::rev, claw_value, rotationUnits::deg);
  }
  else if(!claw_status)
  {
    claw.startRotateFor(directionType::fwd, claw_value, rotationUnits::deg);
  }
}

void Claw_Open()
{  //claw open
  claw.startRotateFor(directionType::fwd, claw_value, rotationUnits::deg);
}


void Claw_Close()
{ //claw close
  claw.startRotateFor(directionType::rev, claw_value, rotationUnits::deg);
}