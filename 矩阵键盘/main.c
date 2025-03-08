#include <REGX52.H>
#include "LCDtools/lcd1602.h"
#include "Matrixkey.h"

void main()
{
	unsigned char result;
	lcd1602_init();//初始化
	lcd1602_show_string(0,0,"HelloWorld");
	while(1)
	{   //反复检测矩阵键盘是否有输入
		result=Matrixkey();//拿到矩阵键盘的输入结果
		if(result!=11
			&&result!=12
			&&result!=13)//当按下显示数字的按钮后
		{
			lcd1602_clear();
			lcd1602_show_string(0,0,&result);//输出数字
		}
	}
}