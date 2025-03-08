#include "Matrixkey.h"
#include <REGX52.H>
unsigned char k;

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

void step(unsigned char* last,unsigned char num,unsigned char* times)
{
	if(*times==4)
		*times=1;
	else
		*times++;
	
	for(k=1;k<4;k++)
	{
		last[k-1]=last[k];
	}
	last[3]=num;
}

unsigned char Matrixkey()
{
	P1=0xFF;
	P1_7=0;
	if(P1_3==0)
	{
		Delay20ms();
		while(P1_3==0);
		return '1';
	}
	if(P1_2==0)
	{
		Delay20ms();
		while(P1_2==0);
		return '2';
	}
	if(P1_1==0)
	{
		Delay20ms();
		while(P1_1==0);
		return '3';
	}
	if(P1_0==0)
	{
		Delay20ms();
		while(P1_0==0);
		return '4';
	}
	P1=0xFF;
	P1_6=0;
	if(P1_3==0)
	{
		Delay20ms();
		while(P1_3==0);
		return '5';
	}
	if(P1_2==0)
	{
		Delay20ms();
		while(P1_2==0);
		return '6';
	}
	if(P1_1==0)
	{
		Delay20ms();
		while(P1_1==0);
		return '7';
	}
	if(P1_0==0)
	{
		Delay20ms();
		while(P1_0==0);
		return '8';
	}
	P1=0xFF;
	P1_5=0;
	if(P1_3==0)
	{
		Delay20ms();
		while(P1_3==0);
		return '9';
	}
	if(P1_2==0)
	{
		Delay20ms();
		while(P1_2==0);
		return '0';
	}
	if(P1_1==0)
	{
		Delay20ms();
		while(P1_1==0);
		return 12;
	}
	if(P1_0==0)
	{
		Delay20ms();
		while(P1_0==0);
		return 13;
	}
	return 11;
}