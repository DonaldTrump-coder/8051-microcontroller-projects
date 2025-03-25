#include <REGX52.H>
#include "LCD1602.h"

sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_E=P2^7;

void Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}

void LCD_writecmd(unsigned char cmd)
{
	LCD_RS=0;
	LCD_RW=0;
	P0=cmd;
	LCD_E=1;
	Delay1ms();
	LCD_E=0;
	Delay1ms();
}

void LCD_writedata(unsigned char val)
{
	LCD_RS=1;
	LCD_RW=0;
	P0=val;
	LCD_E=1;
	Delay1ms();
	LCD_E=0;
	Delay1ms();
}

void LCD_init()
{
	LCD_writecmd(0x38);//8位数据接口
	LCD_writecmd(0x0C);//显示开，光标关，闪烁关
	LCD_writecmd(0x06);//读写操作后，光标自动加一
	LCD_writecmd(0x01);//清屏
}

void LCD_showchar(unsigned char x,unsigned char y,unsigned char val)
{
	LCD_setcursor(x,y);
	LCD_writedata(val);
}

void LCD_showstring(unsigned char x,unsigned char y,unsigned char* val)
{
	unsigned char strp=0;
	LCD_setcursor(x,y);
	while(val[strp]!='\0')
	{
		LCD_writedata(val[strp]);
		strp++;
	}
}

void LCD_setcursor(unsigned char x,unsigned char y)
{
	if(y==1)
	{
		LCD_writecmd(0x80|(x-1));
	}
	else if(y==2)
	{
		LCD_writecmd(0xC0|(x-1));
	}
}

void LCD_shownum(unsigned char x,unsigned char y,unsigned int val,unsigned char len)
{
	unsigned int tens=1;
	unsigned char i;
	unsigned char num;
	for(i=0;i<len-1;i++)
		tens=tens*10;
	LCD_setcursor(x,y);
	for(i=0;i<len;i++)
	{
		num=(unsigned char)((val/tens)%10);
		LCD_writedata(num+'0');
		tens=tens/10;
	}
}

void LCD_showsignednum(unsigned char x,unsigned char y,int val,unsigned char len)
{
	unsigned int num;
	LCD_setcursor(x,y);
	if(val>=0)
	{
		LCD_writedata('+');
		num=val;
	}
	else
	{
		LCD_writedata('-');
		num=-val;
	}
	LCD_shownum(x+1,y,num,len);
}

void LCD_showhex(unsigned char x,unsigned char y,unsigned char val)
{
	unsigned int hex=16;
	unsigned char i;
	unsigned char num;
	LCD_setcursor(x,y);
	for(i=0;i<2;i++)
	{
		num=(unsigned char)((val/hex)%16);
		if(num<10)
		{
			LCD_writedata(num+'0');
		}
		else
		{
			LCD_writedata(num+'A'-10);
		}
		hex=hex/16;
	}
}