#include <REGX52.H>
#include "LCDtools/lcd1602.h"
#include "Matrixkey.h"

void main()
{
	unsigned char result;
	lcd1602_init();//��ʼ��
	lcd1602_show_string(0,0,"HelloWorld");
	while(1)
	{   //��������������Ƿ�������
		result=Matrixkey();//�õ�������̵�������
		if(result!=11
			&&result!=12
			&&result!=13)//��������ʾ���ֵİ�ť��
		{
			lcd1602_clear();
			lcd1602_show_string(0,0,&result);//�������
		}
	}
}