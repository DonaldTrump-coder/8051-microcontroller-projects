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
	while(1)//����������
	{
		while(P3_0==1&&P3_2==1&&P3_3==1)//ִֻ��P31�˿ڵİ����ĳ���
		{
			if(last_bot!=1)
			{
				P2=0xFF;
			}
			if(P3_1==0)//P31�˿ڵİ�������
			{
				last_bot=1;
				P2_0=0;//P20�˿ڵ�LED����
				Delay20ms();
			}
			else
			{
				P2_0=1;//P20�˿ڵ�LEDϨ��
				Delay20ms();
			}
		}
		while(P3_1==1&&P3_2==1&&P3_3==1)//ִֻ��P30�˿ڵİ����ĳ���
		{
			if(last_bot!=0)
			{
				P2=0xFF;
			}
			if(P3_0==0)//P30�˿ڵİ�������
			{
				last_bot=0;
				Delay20ms();
				while(P3_0==0);
				P2_0=~P2_0;
				Delay20ms();
			}
		}
		while(P3_0==1&&P3_1==1&&P3_3==1)//ִֻ��P32�˿ڵİ����ĳ���
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
		while(P3_1==1&&P3_2==1&&P3_0==1)//ִֻ��P33�˿ڵİ����ĳ���
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