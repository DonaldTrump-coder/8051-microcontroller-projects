#include <REGX52.H>

#define L1 0
#define L1_ 1
#define L2 2
#define L2_ 3
#define L3 4
#define L4 5
#define L4_ 6
#define L5 7
#define L5_ 8
#define L6 9
#define L6_ 10
#define L7 11

#define M1 12
#define M1_ 13
#define M2 14
#define M2_ 15
#define M3 16
#define M4 17
#define M4_ 18
#define M5 19
#define M5_ 20
#define M6 21
#define M6_ 22
#define M7 23

#define H1 24
#define H1_ 25
#define H2 26
#define H2_ 27
#define H3 28
#define H4 29
#define H4_ 30
#define H5 31
#define H5_ 32
#define H6 33
#define H6_ 34
#define H7 35

sbit Buzzer=P2^5;
code unsigned int Freq[]={63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
				     64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
                     65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,0};

code unsigned char Music[]={M5,H2,H1,M3,H1,H2,H3,H2,H1,H2,
					   M5,H2,H1,M3,H1,H2,H3,H2,H1,H2,
					   M5,H2,H1,M3,H1,H2,H3,H2,H1,H2,
					   M5,H2,H1,M3,H1,H3,H5,
					   H6,H5,36,H1,
					   H2,H2,H1,H3,36,H3,H5,
					   H6,H7,H6,H5,H3,H2,H2,H1,
					   H2,H2,H3,H1,36,H1,H3,H5};
code unsigned char times[]={2,2,2,4,1,1,1,1,1,1,
					   2,2,2,4,1,1,1,1,1,1,
					   2,2,2,4,1,1,1,1,1,1,
					   2,2,2,4,2,2,2,
					   4,4,4,4,
					   2,2,2,4,2,1,1,
					   2,2,2,2,2,2,2,2,
					   2,2,2,4,1,1,1,1};
unsigned char select;

//1ms
void Timer0_Init(void)		//1??@11.0592MHz
{
	TMOD &= 0xF0;
	TMOD |= 0x01;			//???????
	TL0 = 0x18;				//???????
	TH0 = 0xFC;				//???????
	TF0 = 0;				//??TF0??
	TR0 = 1;				//???0????
	ET0=1;
	EA=1;
	PT0=0;
}

void Timer0_Routine() interrupt 1
{
	TL0=Freq[Music[select]]%256;
	TH0=Freq[Music[select]]/256;
	if(Freq[Music[select]])
	{
		Buzzer=~Buzzer;
	}
}

void Delay5ms(void)	//@11.0592MHz
{
	unsigned char i, j;

	i = 54;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void Delay31ms(unsigned char time)	//@11.0592MHz
{
	unsigned char data i, j, k,h;

	for(h=0;h<time;h++)
	{
		i = 2;
		j = 78;
		k = 121;
		do
		{
			do
			{
				while (--k);
			} while (--j);
		} while (--i);
	}
}


void main()
{
	select=0;
	Timer0_Init();
	while(1)
	{
		Delay31ms(times[select]);
		select++;
		TR0=0;
		Delay5ms();
		TR0=1;
	}
}