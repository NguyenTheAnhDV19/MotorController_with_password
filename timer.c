#include "timer.h"
#include "common.h"

void delay(unsigned int millisecond)
{
	int i;
	for( i =0; i <= millisecond*100;++i);
}