#include "common.h"
#include "timer.h"
#include "lcd.h"
#include "motor.h"
#include "get_key.h"
#include "check.h"
#include "delete.h"

void main()
{
	char password[6] = "35789";
	char input[6] = "";
	char speed[3] = "";
	int error =0;
	int enter =0;
	int motor_run = 0;
	int allow = 3;
	char key_[1];
	int cus_pos = 0xC0;
	command_lcd(0x38);
	command_lcd(0x0C);
	
	command_lcd(0x80);
	display_string("Welcome Anh");
	delay(1000);
	command_lcd(0x01);
	
	while(1)
	{
		if(error == 0 && enter == 1)
		{
			command_lcd(0x80);
			display_string("Enter speed: ");
			command_lcd(cus_pos);
			key_[0] = get_key(&enter,&error,password,speed,&motor_run,&allow);
			display_string(speed);
			if(motor_run == 1)
			{
				run(speed,&motor_run);
			}	
		}
		else if (enter == 0 && allow != 0)
		{
			command_lcd(0x80);
			display_string("Enter password: ");
			command_lcd(cus_pos);
			key_[0] = get_key(&enter,&error,password,input,&motor_run,&allow);
			display_string(input);
		}
		else if (error == 1 && allow != 0)
		{
			command_lcd(0x80);
			display_string("Wrong password");
			delay(1000);
			clear(input,&error,&enter);
		}
		else 
		{
			command_lcd(0x80);
			display_string("Not available!!!");
		}
	}
}

