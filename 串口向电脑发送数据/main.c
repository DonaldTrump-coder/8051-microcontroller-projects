#include <REGX52.H>

void Delay1s(void)	//@11.0592MHz
{
	unsigned char data i, j, k;
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Uart1_Init(void)	//4800bps@11.0592MHz
{
	PCON |= 0x80;		//????????SMOD
	SCON = 0x40;		//8???,?????
	TMOD &= 0x0F;		//???????
	TMOD |= 0x20;		//???????
	TL1 = 0xF3;			//???????
	TH1 = 0xF3;			//???????
	ET1 = 0;			//½ûÖ¹¶¨Ê±Æ÷ÖÐ¶Ï
	TR1 = 1;			//???1????
}

void UART_Send(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

void main()
{
	unsigned char num=0;
	Uart1_Init();
	while(1)
	{
		if(num==0xFF)
		{
			num=0;
		}
		UART_Send(num);
		num++;
		Delay1s();
	}
}