#include "AT24C02.h"
#include "I2C.h"
#include <REGX52.H>

void AT24C02_Write(unsigned char WordAddress,unsigned char val)
{
	bit ack;
	I2C_init();
	I2C_start();
	I2C_send(0xA0);//向AT24C02发送地址数据
	ack=I2C_getack();
	I2C_send(WordAddress);
	ack=I2C_getack();
	I2C_send(val);
	ack=I2C_getack();
	I2C_stop();
}

unsigned char AT24C02_Read(unsigned char WordAddress)
{
	unsigned char val;
	bit ack;
	I2C_init();
	I2C_start();
	I2C_send(0xA0);//向AT24C02发送地址数据
	ack=I2C_getack();
	I2C_send(WordAddress);
	ack=I2C_getack();
	I2C_init();
	I2C_start();
	I2C_send(0xA1);
	ack=I2C_getack();
	val=I2C_get();
	I2C_sendack(1);
	I2C_stop();
	return val;
}