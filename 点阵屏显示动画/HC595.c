#include <REGX52.H>
#include "HC595.h"

sbit RCK=P3^5;//RCLK
sbit SCK=P3^6;//SRCLK
sbit SER=P3^4;//SER

void HC595_init()
{
	SCK=0;
	RCK=0;
}

void Write74HC595(unsigned char val)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if(val&(0x80>>i))
			SER=1;
		else
			SER=0;
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}