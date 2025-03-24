#include "I2C.h"
#include <REGX52.H>

sbit SCL=P2^1;
sbit SDA=P2^0;

void I2C_init()
{
	SDA=1;
	SCL=1;
}

void I2C_start()
{
	I2C_init();
	SDA=0;
	SCL=0;
}

void I2C_stop()
{
	SDA=0;
	SCL=1;
	SDA=1;
}

void I2C_send(unsigned char val)
{
	unsigned char i;
	for(i=0;i<8;i++)//传送八位数据
	{
		SDA=val&(0x80>>i);
		SCL=1;
		SCL=0;
	}
}

unsigned char I2C_get()
{
	unsigned char val,i;
	val=0x00;
	SDA=1;//SDA控制权交给从机
	for(i=0;i<8;i++)
	{
		SCL=1;
		if(SDA)
			val|=(0x80>>i);//读取每一位
		SCL=0;
	}
}

void I2C_sendack(bit ack)
{
	SDA=ack;
	SCL=1;
	SCL=0;
}

bit I2C_getack()
{
	bit ack;
	SDA=1;
	SCL=1;
	ack=SDA;
	SCL=0;
	return ack;
}