#include "delete.h"
#include "lcd.h"

void clear(char* input, int* error, int*enter)
{
	int i;
	for(i =0; input[i] != '\0'; ++i)
	{
		input[i] = '\0';
	}
	*error = 0;
	*enter = 0;
}

void delete_(char* input)
{
	int last_index = strlen(input) - 1;
	input[last_index] = '\0';
	command_lcd(0x01);
}
