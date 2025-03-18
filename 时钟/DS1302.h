#ifndef __DS1302_H__
#define __DS1302_H__

void Write(unsigned char command,unsigned char val);//在指定的单位中写入数据
unsigned char Read(unsigned char command);//读入指定单位中的数据
void DS1302_init();
unsigned char BCD2Hex(unsigned char input);
unsigned char Hex2BCD(unsigned char input);
void Writetime(unsigned char* input);
void Readtime(unsigned char* output);
void Delay1ms(void);

#endif