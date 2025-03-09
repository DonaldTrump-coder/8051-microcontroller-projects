#include "timer.h"
#include <REGX52.H>

count=0;
unsigned char ledmode=0;
void timer0_init()
{
	TMOD=0x01;//定时器工作模式
	TF0=0;
	TR0=1;
	TH0=64535/256;
	TL0=64535%256;
	ET0=1;
	EA=1;
	PT0=0;
}

void cut_progress_ms() interrupt 1
{
    timer0_init();
	count++;
	if(count>=1000)
	{
		count=0;
		if(ledmode==1)
		{
			if(P2==0x7F)
			{
				P2=0xFE;
			}
			else
				P2=~(~(P2)+~(P2));
		}
		if(ledmode==2)
		{
			if(P2==0xFE)
			{
				P2=0x7F;
			}
			else
				P2=~((~P2)/2);
		}
		if(ledmode==3)
		{
			if(P2==0xBF)
			{
				P2=0xFE;
			}
			else
			{
				P2=~(~(P2)+~(P2));
				P2=~(~(P2)+~(P2));
			}
		}
		if(ledmode==4)
		{
			if(P2==0xFD)
			{
				P2=0x7F;
			}
			else
			{
				P2=~((~P2)/2);
				P2=~((~P2)/2);
			}
		}
	}
}