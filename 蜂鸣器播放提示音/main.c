#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"

sbit BEEP=P2^5;
unsigned char keynum;
unsigned int i;

void Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	Nixie(1,0);
	while(1)
	{
		keynum=Key();
		if(keynum)
		{
			Nixie(1,keynum);
			for(i=0;i<500;i++)
			{
				BEEP=~BEEP;
				Delay1ms();
			}
		}
	}
}