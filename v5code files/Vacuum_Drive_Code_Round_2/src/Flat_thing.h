/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\25krugercharles                                  */
/*    Created:      Mon Nov 04 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ---- //
// ---- END VEXCODE CONFIGURED DEVICES ---- //

#include "vex.h"

using namespace vex;  

void Ramp()
{
if(Controller1.ButtonUp.pressing()) //this makes the ramp go up
{
ramp.spin(directionType::fwd, 45, percentUnits::pct);
} 
else if(Controller1.ButtonDown.pressing()) //this makes the ramp go down
{
ramp.spin(directionType::fwd, 45, percentUnits::pct);  
}
}


