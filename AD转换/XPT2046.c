#include "XPT2046.h"
#include <REGX52.H>

sbit XPT_DOUT=P3^7;
sbit XPT_DIN=P3^4;
sbit XPT_CS=P3^5;
sbit XPT_CLK=P3^6;

unsigned int XPT_readAD(unsigned char cmd)
{
	unsigned int val=0;
	unsigned char i;
	XPT_CLK=0;
	XPT_CS=0;
	for(i=0;i<8;i++)
	{
		XPT_DIN=cmd&(0x80>>i);
		XPT_CLK=1;
		XPT_CLK=0;
	}
	XPT_CLK=1;
	for(i=0;i<16;i++)
	{
		XPT_CLK=0;
		if(XPT_DOUT)
			val|=(0x8000>>i);
		XPT_CLK=1;
	}
	XPT_CLK=0;
	XPT_CS=1;
	return (val>>8);
}