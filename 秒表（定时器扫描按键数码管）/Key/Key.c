#include "Key/Key.h"
#include <REGX52.H>

unsigned char lastkey=0;
unsigned char keynum=0;

void Delay20ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 150;
	j = 37;
	do
	{
		while (--j);
	} while (--i);
}

unsigned char key()
{
	unsigned char temp=keynum;
	keynum=0;
	return temp;
}

void Key_Loop()
{
	if(P3_1==0)lastkey=1;
	if(P3_0==0)lastkey=2;
	if(P3_2==0)lastkey=3;
	if(P3_3==0)lastkey=4;
	if(P3_1!=0&&P3_0!=0&&P3_2!=0&&P3_3!=0)
	{
		if(lastkey==1)
		{
			lastkey=0;
			keynum=1;
		}
		if(lastkey==2)
		{
			lastkey=0;
			keynum=2;
		}
		if(lastkey==3)
		{
			lastkey=0;
			keynum=3;
		}
		if(lastkey==4)
		{
			lastkey=0;
			keynum=4;
		}
	}
}