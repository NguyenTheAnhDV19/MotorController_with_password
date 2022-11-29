#include "common.h"

#define keypad P1

extern char get_key( int*enter, int*error, char* password, char* input, int* motor_run, int* allow);