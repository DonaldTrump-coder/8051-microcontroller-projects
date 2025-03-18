#include "DS1302/DS1302.h"
#include <REGX52.H>

sbit SCLK=P3^6;
sbit IO=P3^4;
sbit CE=P3^5;

void DS1302_init()
{
	CE=0;
	SCLK=0;
}

void Write(unsigned char command,unsigned char val)
{
	unsigned char i=0;
	CE=1;
	for(i=0;i<8;i++)
	{
		IO=command&(0x01<<i);
		SCLK=1;
		SCLK=0;
	}
	for(i=0;i<8;i++)
	{
		IO=val&(0x01<<i);
		SCLK=1;
		SCLK=0;
	}
	CE=0;
	IO=0;
}

unsigned char Read(unsigned char command)
{
	unsigned char val=0x00;
	unsigned char i=0;
	CE=1;
	IO=0;
	for(i=0;i<8;i++)
	{
		IO=command&(0x01<<i);
		SCLK=0;
		SCLK=1;
	}
	for(i=0;i<8;i++)
	{
		SCLK=1;
		SCLK=0;
		if(IO)
		{
			val|=(0x01<<i);
		}
	}
	SCLK=0;
	CE=0;
	IO=0;
	return val;
}

unsigned char BCD2Hex(unsigned char input)
{
	unsigned char output;
	output=(input/16)*10+input%16;
	return output;
}

unsigned char Hex2BCD(unsigned char input)
{
	unsigned char output;
	output=(input/10)*16+input%10;
	return output;
}

void Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}

void Writetime(unsigned char* input)
{
	Write(0x8E,0x00);//取消写保护
	Delay1ms();
	Write(0x8C,Hex2BCD(input[0]));
	Delay1ms();
	Write(0x8A,Hex2BCD(input[1]));
	Delay1ms();
	Write(0x88,Hex2BCD(input[2]));
	Delay1ms();
	Write(0x86,Hex2BCD(input[3]));
	Delay1ms();
	Write(0x84,Hex2BCD(input[4]));
	Delay1ms();
	Write(0x82,Hex2BCD(input[5]));
	Delay1ms();
	Write(0x80,Hex2BCD(input[6]));
	Delay1ms();
	Write(0x8E,0x80);//写保护
	Delay1ms();
}

void Readtime(unsigned char* output)
{
	output[0]=BCD2Hex(Read(0x8D));//读入年份信息并转为十进制（十六进制）数
	Delay1ms();
	output[1]=BCD2Hex(Read(0x8B));//读入星期信息并转为十进制（十六进制）数
	Delay1ms();
	output[2]=BCD2Hex(Read(0x89));//读入月份信息并转为十进制（十六进制）数
	Delay1ms();
	output[3]=BCD2Hex(Read(0x87));//读入日期信息并转为十进制（十六进制）数
	Delay1ms();
	output[4]=BCD2Hex(Read(0x85));//读入小时信息并转为十进制（十六进制）数
	Delay1ms();
	output[5]=BCD2Hex(Read(0x83));//读入分信息并转为十进制（十六进制）数
	Delay1ms();
	output[6]=BCD2Hex(Read(0x81));//读入秒信息并转为十进制（十六进制）数
	Delay1ms();
}