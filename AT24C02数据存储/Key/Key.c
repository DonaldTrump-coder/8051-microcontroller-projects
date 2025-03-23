#include "Key/Key.h"
#include <REGX52.H>

void Delay20ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 150;
	j = 37;
	do
	{
		while (--j);
	} while (--i);
}

unsigned char key()
{
	if(P3_1==0)
	{
		Delay20ms();
		while(P3_1==0);
		Delay20ms();
		return 1;
	}
	if(P3_0==0)
	{
		Delay20ms();
		while(P3_1==0);
		Delay20ms();
		return 2;
	}
	if(P3_2==0)
	{
		Delay20ms();
		while(P3_1==0);
		Delay20ms();
		return 3;
	}
	if(P3_3==0)
	{
		Delay20ms();
		while(P3_1==0);
		Delay20ms();
		return 4;
	}
	return 0;
}