#include <REGX52.H>
#include "timer.h"
#include "Nixie.h"
#include "Key/Key.h"
#include "AT24C02.h"

unsigned char count1=0;
unsigned char count2=0;
unsigned char count3=0;
unsigned char Mins,Secs,Minsecs;
bit run;

void Delay5ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 54;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	timer0_init();
	Mins=Secs=Minsecs=0;
	while(1)
	{
		if(key()==1)
			run=~run;
		if(key()==2)
			Mins=Secs=Minsecs=0;
		if(key()==3)
		{
			AT24C02_Write(0,Mins);
			Delay5ms();
			AT24C02_Write(1,Secs);
			Delay5ms();
			AT24C02_Write(2,Minsecs);
		}
		if(key()==4)
		{
			Mins=AT24C02_Read(0);
			Secs=AT24C02_Read(1);
			Minsecs=AT24C02_Read(2);
		}
		setbuf(1,Mins/10);
		setbuf(2,Mins%10);
		setbuf(3,11);
		setbuf(4,Secs/10);
		setbuf(5,Secs%10);
		setbuf(6,11);
		setbuf(7,Minsecs/10);
		setbuf(8,Minsecs%10);
	}
}

void time_Loop()
{
	if(run==1)
	{
		Minsecs++;
		if(Minsecs>=10)
		{
			Minsecs=0;
			Secs++;
			if(Secs>=60)
			{
				Secs=0;
				Mins++;
				if(Mins>=60)
				Mins=0;
			}
		}
	}
	
}

void Timer0_Routine() interrupt 1
{
	TL0=0x18;
	TH0=0xFC;
	count1++;
	count2++;
	count3++;
	if(count1>=20)
	{
		count1=0;
		Key_Loop();
	}
	if(count2>=2)
	{
		count2=0;
		Nixie_Loop();
	}
	if(count3>=100)
	{
		count3=0;
		time_Loop();
	}
}