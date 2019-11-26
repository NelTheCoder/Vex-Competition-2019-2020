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

using namespace vex;  
 
void Vacuum() 
{  //vacuum motors spin
if(Controller1.ButtonL2.pressing()) //UwU by noa
{
  vacuum_left.spin(directionType::fwd, 45 , percentUnits::pct);
  vacuum_right.spin(directionType::fwd, 45 , percentUnits::pct);
}
else 
{ //when nothing is happening, the motors stop
 vacuum_left.stop();
 vacuum_right.stop();
}
}