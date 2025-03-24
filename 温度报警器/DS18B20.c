#include "DS18B20.h"
#include "One_bus.h"

void DS18B20_convert()
{
	One_bus_Init();
	One_bus_sendbyte(0xCC);//Skip ROM
	One_bus_sendbyte(0x44);
}

float DS18B20_read()
{
	unsigned char TLSB,TMSB;
	float temperature;
	int temp;
	One_bus_Init();
	One_bus_sendbyte(0xCC);//Skip ROM
	One_bus_sendbyte(0xBE);//read
	TLSB=One_bus_getbyte();
	TMSB=One_bus_getbyte();
	temp=(TMSB<<8)|TLSB;
	temperature=temp/16.0;
	return temperature;
}