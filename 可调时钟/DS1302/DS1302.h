#ifndef __DS1302_H__
#define __DS1302_H__

void DS1302_init();
void Write(unsigned char command,char val);//��ָ���ĵ�λ��д������
unsigned char Read(unsigned char command);//����ָ����λ�е�����
unsigned char BCD2Hex(unsigned char input);//BCD��תΪʮ���ƣ�ʮ�����ƣ���
unsigned char Hex2BCD(unsigned char input);//ʮ���ƣ�ʮ�����ƣ���תΪBCD��
void Writetime(unsigned char* input);//д��ָ�������е�ʱ����DS1302
void Readtime(unsigned char* output);//����ʱ����Ϣ��ָ����������
void Delay1ms(void);//�ӳ�1ms

#endif