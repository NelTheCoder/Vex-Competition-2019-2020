#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Top_left = motor(PORT11, ratio18_1, true);
motor Bottom_left = motor(PORT13, ratio18_1, true);
motor Top_right = motor(PORT12, ratio18_1, true);
motor Bottom_right = motor(PORT14, ratio18_1, true);
motor Lift_left = motor(PORT1, ratio36_1, false);
motor Lift_right = motor(PORT2, ratio36_1, true);
motor claw = motor(PORT19, ratio36_1, true);
controller Controller1 = controller(primary);
pot Left_pot = pot(Brain.ThreeWirePort.B);
pot Right_pot = pot(Brain.ThreeWirePort.A);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}