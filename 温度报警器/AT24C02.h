#ifndef __AT24C02_H__
#define __AT24C02_H__

void AT24C02_Write(unsigned char WordAddress,unsigned char val);
unsigned char AT24C02_Read(unsigned char WordAddress);

#endif