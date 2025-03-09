#include "key.h"
#include <REGX52.H>

void Delay20ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 216;
	j = 37;
	do
	{
		while (--j);
	} while (--i);
}

unsigned char keys()
{
	unsigned char key=0;
	if(P3_1==0)
	{
		Delay20ms();
		while(P3_1==0);
		key=1;
		Delay20ms();
		return key;
	}
	if(P3_2==0)
	{
		Delay20ms();
		while(P3_2==0);
		key=3;
		Delay20ms();
		return key;
	}
	if(P3_3==0)
	{
		Delay20ms();
		while(P3_3==0);
		key=4;
		Delay20ms();
		return key;
	}
	if(P3_0==0)
	{
		Delay20ms();
		while(P3_0==0);
		key=2;
		Delay20ms();
		return key;
	}
	return key;
}