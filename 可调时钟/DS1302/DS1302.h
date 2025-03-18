#ifndef __DS1302_H__
#define __DS1302_H__

void DS1302_init();
void Write(unsigned char command,char val);//在指定的单位中写入数据
unsigned char Read(unsigned char command);//读入指定单位中的数据
unsigned char BCD2Hex(unsigned char input);//BCD码转为十进制（十六进制）数
unsigned char Hex2BCD(unsigned char input);//十进制（十六进制）数转为BCD码
void Writetime(unsigned char* input);//写入指定数组中的时间至DS1302
void Readtime(unsigned char* output);//读入时间信息至指定的数组中
void Delay1ms(void);//延迟1ms

#endif