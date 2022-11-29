#include "timer.h"
#include "common.h"
#include "get_key.h"
#include "check.h"
#include "lcd.h"
#include "delete.h"

char get_key( int* enter, int* error, char* password, char* input, int* motor_run, int* allow)
{
		char key[1];
		key[0] = 0;
	
		keypad = 0xF7;
		if(keypad == 0xF3)
		{
			delay(50);
			key[0] = '1';
			strncat(input,key,1);
		}
		else if(keypad == 0xF5)
		{
			delay(50);
			key[0] = '2';
			strncat(input,key,1);
		}
		else if(keypad == 0xF6)
		{
			delay(50);
			key[0] = '3';
			strncat(input,key,1);
		}
		keypad = 0xEF;
		if(keypad == 0xED)
		{
			delay(50);
			key[0] = '5';
			strncat(input,key,1);
		}
		else if(keypad == 0xEB)
		{
			delay(50);
			key[0] = '4';
			strncat(input,key,1);
		}
		else if(keypad == 0xEE)
		{
			delay(50);
			key[0] = '6';
			strncat(input,key,1);
		}
	
		keypad = 0xDF;
	
		if(keypad == 0xDD)
		{
			delay(50);
			key[0] = '8';
			strncat(input,key,1);
		}
		else if(keypad == 0xDB)
		{
			delay(50);
			key[0] = '7';
			strncat(input,key,1);
		}
		else if(keypad == 0xDE)
		{
			delay(50);
			key[0] = '9';
			strncat(input,key,1);
		}
	
	  keypad = 0xBF;
	
		if(keypad == 0xBB)
		{
			delay(50);
			key[0] = '*';
			delete_(input);
		}
		else if(keypad == 0xBD)
		{
			delay(50);
			key[0] = '0';
			strncat(input,key,1);
		}
		else if(keypad == 0xBE)
		{
			delay(50);
			if(*enter == 1 && *error == 0) {*motor_run = 1;}
			*enter = 1;
			command_lcd(0x01);
			if(*motor_run != 1) {check(input,password,error,allow);}
		}
		return key[0];
}
	