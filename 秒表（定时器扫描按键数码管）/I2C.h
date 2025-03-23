#ifndef __I2C_H__
#define __I2C_H__

void I2C_init();//I2C_start()Ç°Ê¹ÓÃ
void I2C_start();
void I2C_stop();
void I2C_send(unsigned char val);
unsigned char I2C_get();
void I2C_sendack(bit ack);
bit I2C_getack();

#endif