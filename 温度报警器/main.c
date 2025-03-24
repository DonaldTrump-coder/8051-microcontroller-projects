#include "Key/Key.h"
#include "timer.h"
#include <REGX52.H>
#include "AT24C02.h"
#include "LCDtools/lcd1602.h"
#include "DS18B20.h"

unsigned char count1;
float T;
float TH,TL;

void main()
{
	unsigned char keynum;
	if(AT24C02_Read(0)==1)
		TL=(float)AT24C02_Read(1);
	else
	{
		TL=(float)AT24C02_Read(1);
		TL=-TL;
	}
	if(AT24C02_Read(2)==1)
		TH=(float)AT24C02_Read(3);
	else
	{
		TL=(float)AT24C02_Read(3);
		TL=-TH;
	}
	if(TL>=0)
	{
		AT24C02_Write(0,1);
		AT24C02_Write(1,(unsigned char)(int)TL);
	}
	else
	{
		AT24C02_Write(0,0);
		AT24C02_Write(1,(unsigned char)(int)TL);
	}
	if(TH>=0)
	{
		AT24C02_Write(2,1);
		AT24C02_Write(3,(unsigned char)(int)TH);
	}
	else
	{
		AT24C02_Write(2,0);
		AT24C02_Write(3,(unsigned char)(int)TH);
	}
	timer0_init();
	lcd1602_init();
	lcd1602_show_string(0,0,"Temp:");
	while(1)
	{
		keynum=0;
		keynum=key();
		if(keynum==1)
		{
			TL++;
			if(TL>=0)
			{
				AT24C02_Write(0,1);
				AT24C02_Write(1,(unsigned char)(int)TL);
			}
			else
			{
				AT24C02_Write(0,0);
				AT24C02_Write(1,(unsigned char)(int)TL);
			}
			if(TH>=0)
			{
				AT24C02_Write(2,1);
				AT24C02_Write(3,(unsigned char)(int)TH);
			}
			else
			{
				AT24C02_Write(2,0);
				AT24C02_Write(3,(unsigned char)(int)TH);
			}
		}
		if(keynum==2)
		{
			TL--;
			if(TL>=0)
			{
				AT24C02_Write(0,1);
				AT24C02_Write(1,(unsigned char)(int)TL);
			}
			else
			{
				AT24C02_Write(0,0);
				AT24C02_Write(1,(unsigned char)(int)TL);
			}
			if(TH>=0)
			{
				AT24C02_Write(2,1);
				AT24C02_Write(3,(unsigned char)(int)TH);
			}
			else
			{
				AT24C02_Write(2,0);
				AT24C02_Write(3,(unsigned char)(int)TH);
			}
		}
		if(keynum==3)
		{
			TH++;
			if(TL>=0)
			{
				AT24C02_Write(0,1);
				AT24C02_Write(1,(unsigned char)(int)TL);
			}
			else
			{
				AT24C02_Write(0,0);
				AT24C02_Write(1,(unsigned char)(int)TL);
			}
			if(TH>=0)
			{
				AT24C02_Write(2,1);
				AT24C02_Write(3,(unsigned char)(int)TH);
			}
			else
			{
				AT24C02_Write(2,0);
				AT24C02_Write(3,(unsigned char)(int)TH);
			}
		}
		if(keynum==4)
		{
			TH--;
			if(TL>=0)
			{
				AT24C02_Write(0,1);
				AT24C02_Write(1,(unsigned char)(int)TL);
			}
			else
			{
				AT24C02_Write(0,0);
				AT24C02_Write(1,(unsigned char)(int)TL);
			}
			if(TH>=0)
			{
				AT24C02_Write(2,1);
				AT24C02_Write(3,(unsigned char)(int)TH);
			}
			else
			{
				AT24C02_Write(2,0);
				AT24C02_Write(3,(unsigned char)(int)TH);
			}
		}
		DS18B20_convert();
		T=DS18B20_read();
		lcd1602_show_unsigned_char_temperature(5,0,T);
		if(TL>=0)
			{
				lcd1602_show_string(0,1,"TL:+");
				lcd1602_show_unsigned_char(4,1,(unsigned char)(int)TL);
			}
		else
		{
			lcd1602_show_string(0,1,"TL:-");
			lcd1602_show_unsigned_char(4,1,(unsigned char)(int)(-TL));
		}
		if(TH>=0)
		{
			lcd1602_show_string(9,1,"TH:+");
			lcd1602_show_unsigned_char(13,1,(unsigned char)(int)TH);
		}
		else
		{
			lcd1602_show_string(9,1,"TH:-");
			lcd1602_show_unsigned_char(13,1,(unsigned char)(int)(-TH));
		}
			
		if(T<TL)
			lcd1602_show_string(14,0,"L!");
		else if(T>TH)
			lcd1602_show_string(14,0,"H!");
		else
			lcd1602_show_string(14,0,"  ");
	}
}

void Timer0_Routine() interrupt 1
{
	TL0=0x18;
	TH0=0xFC;
	count1++;
	if(count1>=20)
	{
		count1=0;
		Key_Loop();
	}
}