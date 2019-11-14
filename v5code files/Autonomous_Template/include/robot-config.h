using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Top_left;
extern motor Bottom_left;
extern motor Top_right;
extern motor Bottom_right;
extern motor Lift_left;
extern motor Lift_right;
extern motor claw;
extern motor vacuum_left;
extern motor vacuum_right;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );