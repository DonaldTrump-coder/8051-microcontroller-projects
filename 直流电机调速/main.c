#include <REGX52.H>
#include "Key/Key.h"
#include "timer.h"
#include "Nixie.h"
#include <REGX52.H>

unsigned char counter=0;
unsigned char object,speed;

void main()
{
	unsigned char keynum;
	timer0_init();
	speed=0;
	object=0;
	Nixie(1,speed);
	while(1)
	{
		keynum=key();
		if(keynum==1)
		{
			speed++;
			if(speed>3)speed=0;
			if(speed==0)object=0;
			if(speed==1)object=40;
			if(speed==2)object=100;
			if(speed==3)object=200;
		}
		Nixie(1,speed);
	}
}

void Timer0_Routine() interrupt 1
{
	TL0=0x9C;
	TH0=0xFF;//100us
	counter++;
	if(counter>200)counter==0;
	if(counter>object)
		P1_0=0;
	else
		P1_0=1;
}