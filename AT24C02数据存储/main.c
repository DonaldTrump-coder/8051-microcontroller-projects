#include <REGX52.H>
#include "Key/Key.h"
#include "Public/public.h"
#include "LCDtools/lcd1602.h"
#include "AT24C02.h"

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

void Delay300ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	i = 22;
	j = 3;
	k = 127;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	unsigned char keynum,num;
	num=0;
	lcd1602_init();
	lcd1602_show_unsigned_char(0,0,num);
	while(1)
	{
		keynum=key();
		switch(keynum)
		{
			case 1:if(num==255)num==0;
				   num++;
				   lcd1602_show_unsigned_char(0,0,num);
				   break;
			case 2:if(num==0)num=255;
				   num--;
				   lcd1602_show_unsigned_char(0,0,num);
				   break;
			case 3:AT24C02_Write(1,num);
				   lcd1602_show_string(0,0,"stored");
				   Delay300ms();
			       lcd1602_clear();
				   lcd1602_show_unsigned_char(0,0,num);
			       Delay5ms();
				   break;
			case 4:num=AT24C02_Read(1);
			       lcd1602_show_string(0,0,"read");
				   Delay300ms();
				   lcd1602_clear();
			       lcd1602_show_unsigned_char(0,0,num);
			       Delay5ms();
			       AT24C02_Write(1,num);
			       Delay5ms();
				   break;
		}
	}
}