#include "One_bus.h"
#include <REGX52.H>

sbit DQ=P3^7;

void Delay485us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 221;
	while (--i);
}

void Delay70us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 29;
	while (--i);
}

void Delay9us(void)	//@11.0592MHz
{
	unsigned char data i;

	i = 1;
	while (--i);
}

unsigned char One_bus_Init()//初始化单总线
{
	bit i;
	DQ=1;
	DQ=0;
	Delay485us();
	DQ=1;
	Delay70us();
	i=DQ;
	Delay485us();
	return i;
}

void One_bus_send(bit val)
{	
	unsigned char data i;
	DQ=0;
	Delay9us();
	DQ=val;
	i = 22;
	while (--i);//delay 50 us
	DQ=1;
}

bit One_bus_get()
{
	bit val;
	unsigned char data i;
	DQ=0;
	i = 2;
	while (--i);//Delay 5 us
	DQ=1;
	i = 2;
	while (--i);//Delay 5 us
	val=DQ;
	i = 22;
	while (--i);//Delay 50 us
	return val;
}

void One_bus_sendbyte(unsigned char val)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		One_bus_send(val&(0x01<<i));
	}
}

unsigned char One_bus_getbyte()
{
	unsigned char val,i;
	val=0x00;
	for(i=0;i<8;i++)
	{
		if(One_bus_get()==1)
		{
			val|=(0x01<<i);
		}
	}
	return val;
}