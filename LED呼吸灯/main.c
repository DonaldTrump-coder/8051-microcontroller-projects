#include <REGX52.H>

void Delay(unsigned char t)
{
	while(t--);
}

void main()
{
	unsigned char Time,a;
	P0=0xFF;
	while(1)
	{
		for(Time=0;Time<200;Time++)
		{
			for(a=0;a<20;a++)
			{
				P2_0=0;
				Delay(Time);
				P2_0=1;
				Delay(200-Time);
			}
		}
		for(Time=0;Time<200;Time++)
		{
			for(a=0;a<20;a++)
			{
				P2_0=1;
				Delay(Time);
				P2_0=0;
				Delay(200-Time);
			}
		}
	}
}