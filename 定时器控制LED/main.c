#include <REGX52.H>
#include "timer.h"
#include "key.h"

void main()
{
	unsigned char last;
	unsigned char key;
	timer0_init();
	while(1)
	{
		key=keys();
		if(key==1)
		{
			if(last!=1)
			{
				P2=0xFE;
			}
			last=1;
			ledmode=1;
		}
		if(key==2)
		{
			if(last!=2)
			{
				P2=0x7F;
			}
			last=2;
			ledmode=2;
		}
		if(key==3)
		{
			if(last!=3)
			{
				P2=0xFE;
			}
			last=3;
			ledmode=3;
		}
		if(key==4)
		{
			if(last!=4)
			{
				P2=0x7F;
			}
			last=4;
			ledmode=4;
		}
	}
}