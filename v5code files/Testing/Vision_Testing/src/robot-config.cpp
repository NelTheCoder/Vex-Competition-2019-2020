#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature Vision__ORANGE_CUBE = signature (1, 6671, 8659, 7665, -2243, -1557, -1900, 5.9, 0);
signature Vision__GREEN_CUBE = signature (2, -7841, -5221, -6531, -4097, -2161, -3129, 3.2, 0);
signature Vision__PURPLE_CUBE = signature (3, 503, 2061, 1282, 5537, 12171, 8854, 2.1, 0);
signature Vision__SIG_4 = signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_5 = signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_6 = signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
signature Vision__SIG_7 = signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vision Vision = vision (PORT1, 50, Vision__ORANGE_CUBE, Vision__GREEN_CUBE, Vision__PURPLE_CUBE, Vision__SIG_4, Vision__SIG_5, Vision__SIG_6, Vision__SIG_7);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}