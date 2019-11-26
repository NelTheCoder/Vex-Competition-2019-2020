/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\25krugercharles                                  */
/*    Created:      Mon Nov 18 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// vacuum_left          motor         3               
// vacuum_right         motor         4               
// Controller1          controller                    
// Top_left             motor         11              
// Top_right            motor         12              
// Bottom_left          motor         13              
// Bottom_right         motor         14              
// ramp                 motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

//files to include
#include "vex.h"
#include "driving.h"
#include "Flat_thing.h"


//necessary jargon for easier usage of Vex C++
using namespace vex;

//main function where actual code is
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while(true) 
  {
    //driving functions
    Driving();
    Vacuum();
  }
}

