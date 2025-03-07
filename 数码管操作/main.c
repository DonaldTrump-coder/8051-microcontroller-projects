#include <REGX52.H>

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

void Delay100us(void)	//@11.0592MHz
{
	unsigned char data i, j;
	i = 2;
	j = 15;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	while(1)
	{
		if(P3_1==0)
		{
			P2_4=1;
			P2_3=0;
			P2_2=1;
			P0=0x7D;
			Delay20ms();
		}
		else
		{
			P0=0;
			P2=255;
		}
		while(P3_0==0)
		{
			P2_4=1;
			P2_3=1;
			P2_2=1;
			P0=0x06;
			Delay100us();
			P0=0;
			P2=255;
			P2_4=1;
			P2_3=1;
			P2_2=0;
			P0=0x5B;
			Delay100us();
			P0=0;
			P2=255;
			P2_4=1;
			P2_3=0;
			P2_2=1;
			P0=0x4F;
			Delay100us();
			P0=0;
			P2=255;
		}
	}
}