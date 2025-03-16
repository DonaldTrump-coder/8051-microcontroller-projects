#include <REGX52.H>
#include "HC595.h"

void Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;
	i = 5;
	j = 80;
	do
	{
		while (--j);
	} while (--i);
}

void MatrixLED_showcolumn(unsigned char column,unsigned char val)
{
	Write74HC595(val);
	if(column==1)
		P0=~0x80;
	if(column==2)
		P0=~0x40;
	if(column==3)
		P0=~0x20;
	if(column==4)
		P0=~0x10;
	if(column==5)
		P0=~0x08;
	if(column==6)
		P0=~0x04;
	if(column==7)
		P0=~0x02;
	if(column==8)
		P0=~0x01;
	Delay1ms();
	P0=~0x00;
}

void main()
{
	unsigned char column=1;
	HC595_init();
	while(1)
	{
		MatrixLED_showcolumn(1,0x3C);
		MatrixLED_showcolumn(2,0x42);
		MatrixLED_showcolumn(3,0xA9);
		MatrixLED_showcolumn(4,0x85);
		MatrixLED_showcolumn(5,0x85);
		MatrixLED_showcolumn(6,0xA9);
		MatrixLED_showcolumn(7,0x42);
		MatrixLED_showcolumn(8,0x3C);
	}
}