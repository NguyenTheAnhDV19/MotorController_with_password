#include "motor.h"
#include "timer.h"

void run(char* input, int* motor_run)
{
	int speed = atoi(input);
	motor_pin1 = 0;
	motor_pin2 = 0;
	if(speed != 0)
	{
		delay(10- speed);
		motor_pin1 = 1;
		motor_pin2 = 0;
	}
	else 
	{
		*motor_run = 0;
	}
}

