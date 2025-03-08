#include <REGX52.H>
#include "LCDtools/lcd1602.h"
#include "Matrixkey.h"

void main()
{
	unsigned char result;
	unsigned char times=1;
	unsigned char password[4]={'1','2','3','4'};
	unsigned char last[4]={'0','0','0','0'};
	lcd1602_init();//初始化
	lcd1602_show_string(0,0,"Password:");
	lcd1602_show_string(0,1,"0000");
	while(1)
	{   //反复检测矩阵键盘是否有输入
		result=Matrixkey();//拿到矩阵键盘的输入结果
		if(result!=11
			&&result!=12
			&&result!=13)//当按下显示数字的按钮后
		{
			step(last,result,&times);
			lcd1602_show_string(0,1,last);//输出数字
		}
		if(result==12)
		{
			if(last[0]==password[0]&&last[1]==password[1]&&last[2]==password[2]&&last[3]==password[3])
				lcd1602_show_string(14,0,"ok");
			else
				lcd1602_show_string(14,0,"no");
		}
		if(result==13)
		{
			times=1;
			lcd1602_show_string(0,1,"0000");
			last[0]=last[1]=last[2]=last[3]='0';
			lcd1602_show_string(14,0,"  ");
		}
	}
}