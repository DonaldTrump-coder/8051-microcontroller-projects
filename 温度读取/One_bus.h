#ifndef __ONEBUS_H__
#define __ONEBUS_H__

unsigned char One_bus_Init();
void One_bus_send(bit val);
bit One_bus_get();
void One_bus_sendbyte(unsigned char val);
unsigned char One_bus_getbyte();

#endif