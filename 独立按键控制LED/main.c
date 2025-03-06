//#include <STC89C5xRC.H>
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

void main()
{
	unsigned char last_bot;
	unsigned char LED;
	unsigned char max=0;
	while(P3_0==1&&P3_1==1&&P3_2==1&&P3_3==1);
	while(1)//主程序内容
	{
		while(P3_0==1&&P3_2==1&&P3_3==1)//只执行P31端口的按键的程序
		{
			if(last_bot!=1)
			{
				P2=0xFF;
			}
			if(P3_1==0)//P31端口的按键按下
			{
				last_bot=1;
				P2_0=0;//P20端口的LED点亮
				Delay20ms();
			}
			else
			{
				P2_0=1;//P20端口的LED熄灭
				Delay20ms();
			}
		}
		while(P3_1==1&&P3_2==1&&P3_3==1)//只执行P30端口的按键的程序
		{
			if(last_bot!=0)
			{
				P2=0xFF;
			}
			if(P3_0==0)//P30端口的按键按下
			{
				last_bot=0;
				Delay20ms();
				while(P3_0==0);
				P2_0=~P2_0;
				Delay20ms();
			}
		}
		while(P3_0==1&&P3_1==1&&P3_3==1)//只执行P32端口的按键的程序
		{	
			if(last_bot!=2)
			{
				LED=0;
				P2=~LED;
			}
			if(P3_2==0)
			{
				last_bot=2;
				Delay20ms();
				while(P3_2==0);
				LED++;
				P2=~LED;
				Delay20ms();
			}
		}
		while(P3_1==1&&P3_2==1&&P3_0==1)//只执行P33端口的按键的程序
		{
			if(last_bot!=3)
			{
				LED=0;
				P2=~LED;
			}
			if(P3_3==0)
			{
				Delay20ms();
				while(P3_3==0);
				if(last_bot!=3||max==1)
				{
					LED=0x01;
					max=0;
				}
				else
				{
					LED=LED+LED;
				}
				last_bot=3;
				if(LED==128)
				{
					max=1;
				}
				else
					max=0;
				P2=~LED;
				Delay20ms();
			}
		}
	}
}