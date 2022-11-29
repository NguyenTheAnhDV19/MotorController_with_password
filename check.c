#include <check.h>

void check(char* input, char* password, int* error, int*allow)
{
		int count = 0;
		int i;
		for(i =0; password[i] != '\0'; ++i)
		{
			if(input[i] != password[i])
			{
				*error = 1;
				*allow -=1;
				break;
			}
		}
}