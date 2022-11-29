#include "common.h"

sbit motor_pin1 = P3^2 ;
sbit motor_pin2 = P3^3 ;

void run(char* input, int* motor_run);