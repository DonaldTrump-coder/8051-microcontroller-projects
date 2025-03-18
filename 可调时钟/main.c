#include <REGX52.H>
#include "Key/Key.h"
#include "LCDtools/lcd1602.h"
#include "DS1302/DS1302.h"

unsigned char time[]={25,2,3,18,13,12,02};
unsigned char timegot[]={25,2,3,18,13,12,31};
bit Mode;

void Timeshow()//显示当前时间
{
	Readtime(timegot);
	lcd1602_show_string(6,0,"20");
	lcd1602_show_unsigned_char_time(8,0,timegot[0]);
	lcd1602_show_string(10,0,"/");
	lcd1602_show_unsigned_char_time(11,0,timegot[2]);
	lcd1602_show_string(13,0,"/");
	lcd1602_show_unsigned_char_time(14,0,timegot[3]);
	lcd1602_show_unsigned_char_time(0,1,timegot[4]);
	lcd1602_show_string(2,1,":");
	lcd1602_show_unsigned_char_time(3,1,timegot[5]);
	lcd1602_show_string(5,1,":");
	lcd1602_show_unsigned_char_time(6,1,timegot[6]);
	if(timegot[1]==1)
		lcd1602_show_string(9,1,"Mon");
	if(timegot[1]==2)
		lcd1602_show_string(9,1,"Tues");
	if(timegot[1]==3)
		lcd1602_show_string(9,1,"Wed");
	if(timegot[1]==4)
		lcd1602_show_string(9,1,"THURS");
	if(timegot[1]==5)
		lcd1602_show_string(9,1,"FRI");
	if(timegot[1]==6)
		lcd1602_show_string(9,1,"SAT");
	if(timegot[1]==7)
		lcd1602_show_string(9,1,"SUN");
}

void staticTimeshow(unsigned char timeset,bit light)//显示时间，但不读取，只显示当前timegot数组中的内容
{
	if(light==1||timeset!=5)//不闪烁或处于闪烁的可见阶段
	{
		lcd1602_show_string(6,0,"20");//年份开头前两位常量
		lcd1602_show_unsigned_char_time(8,0,timegot[0]);//年份的最后两位
	}
	lcd1602_show_string(10,0,"/");
	if(light==1||timeset!=4)
	{
		lcd1602_show_unsigned_char_time(11,0,timegot[2]);
	}
	lcd1602_show_string(13,0,"/");
	if(light==1||timeset!=3)
	{
		lcd1602_show_unsigned_char_time(14,0,timegot[3]);
	}
	if(light==1||timeset!=2)
	{
		lcd1602_show_unsigned_char_time(0,1,timegot[4]);
	}
	lcd1602_show_string(2,1,":");
	if(light==1||timeset!=1)
	{
		lcd1602_show_unsigned_char_time(3,1,timegot[5]);
	}
	lcd1602_show_string(5,1,":");
	if(light==1||timeset!=0)
	{
		lcd1602_show_unsigned_char_time(6,1,timegot[6]);
	}
	if(light==1||timeset!=6)
	{
		if(timegot[1]==1)
			lcd1602_show_string(9,1,"Mon");
		if(timegot[1]==2)
			lcd1602_show_string(9,1,"Tues");
		if(timegot[1]==3)
			lcd1602_show_string(9,1,"Wed");
		if(timegot[1]==4)
			lcd1602_show_string(9,1,"THURS");
		if(timegot[1]==5)
			lcd1602_show_string(9,1,"FRI");
		if(timegot[1]==6)
			lcd1602_show_string(9,1,"SAT");
		if(timegot[1]==7)
			lcd1602_show_string(9,1,"SUN");
	}
	if(light==0)//闪烁的不显示阶段
	{
		if(timeset==0)
		{
			lcd1602_show_string(6,1,"  ");
		}
		else if(timeset==1)
		{
			lcd1602_show_string(3,1,"  ");
		}
		else if(timeset==2)
		{
			lcd1602_show_string(0,1,"  ");
		}
		else if(timeset==3)
		{
			lcd1602_show_string(14,0,"  ");
		}
		else if(timeset==4)
		{
			lcd1602_show_string(11,0,"  ");
		}
		else if(timeset==5)
		{
			lcd1602_show_string(6,0,"    ");
		}
		else if(timeset==6)
		{
			lcd1602_show_string(9,1,"     ");
		}
	}
}

void Timeset()//时间设置功能
{
	unsigned char keynum,count,timeset=0;
	bit light=1;//判断是否处于闪烁阶段
	Readtime(timegot);//进入时间设置模式时只在最开始获取一次当前时间
	while(1)
	{
		count++;
		if(count>4)//控制闪烁的时间间隔长短
		{
			count=0;
			light=~light;
		}
		staticTimeshow(timeset,light);//静态显示闪烁时间，以保证时间设置状态下显示的时间不会随时间变化
		keynum=key();//按键读取模式
		if(keynum==1)//设置完时间后切换为时间显示模式
		{
			Mode=~Mode;
			Writetime(timegot);//将设置的时间同时写入当前时间
			return;
		}
		if(keynum==2)//改变需要修改的不同时间单位
		{
			timeset++;
			if(timeset>6)timeset=0;
		}
		if(keynum==3)//选中的时间单位加一
		{
			switch(timeset)
			{
				case 0:timegot[6]++;break;//秒+1
				case 1:timegot[5]++;break;//分+1
				case 2:timegot[4]++;break;//时+1
				case 3:timegot[3]++;break;//日+1
				case 4:timegot[2]++;break;//月+1
				case 5:timegot[0]++;break;//年+1
				case 6:timegot[1]++;break;//星期+1
			}
			if(timegot[0]>99)timegot[0]=0;//年份越界判断
			if(timegot[1]>7)timegot[1]=1;//星期越界判断
			if(timegot[2]>12)timegot[2]=1;//月份越界判断
			
			if(timegot[2]==2&&timegot[0]%4==0)//结合闰年2月及大小年进行日期越界判断
			{
				if(timegot[3]>29)timegot[3]=1;
			}
			else if(timegot[2]==2)
			{
				if(timegot[3]>28)timegot[3]=1;
			}
			else if(timegot[2]==4||timegot[2]==6||timegot[2]==9||timegot[2]==11)
			{
				if(timegot[3]>30)timegot[3]=1;
			}
			else
			{
				if(timegot[3]>31)timegot[3]=1;
			}
			
			if(timegot[4]>23)timegot[4]=0;
			if(timegot[5]>59)timegot[5]=0;
			if(timegot[6]>59)timegot[6]=0;
		}
		if(keynum==4)//选中的时间单位减一
		{
			if(timegot[0]==0)timegot[0]=100;
			
			if(timegot[4]==0)timegot[4]=24;
			if(timegot[5]==0)timegot[5]=60;
			if(timegot[6]==0)timegot[6]=60;
			
			switch(timeset)
			{
				case 0:timegot[6]--;break;//秒-1
				case 1:timegot[5]--;break;//分-1
				case 2:timegot[4]--;break;//时-1
				case 3:timegot[3]--;break;//日-1
				case 4:timegot[2]--;break;//月-1
				case 5:timegot[0]--;break;//年-1
				case 6:timegot[1]--;break;//星期-1
			}
			if(timegot[1]==0)timegot[1]=7;
			if(timegot[2]==0)timegot[2]=12;
			
			if(timegot[2]==2&&timegot[0]%4==0)
			{
				if(timegot[3]==0)timegot[3]=29;
			}
			else if(timegot[2]==2)
			{
				if(timegot[3]==0)timegot[3]=28;
			}
			else if(timegot[2]==4||timegot[2]==6||timegot[2]==9||timegot[2]==11)
			{
				if(timegot[3]==0)timegot[3]=30;
			}
			else
			{
				if(timegot[3]==0)timegot[3]=31;
			}
		}
	}
}

void main()
{
	unsigned char keynum;
	DS1302_init();
	lcd1602_init();
	
	lcd1602_show_string(0,0,"Time:");
	Write(0x8E,0x00);//取消写保护
	Delay1ms();
	Writetime(time);//写入指定的时间
	Mode=0;//默认为时间显示模式
	while(1)
	{
		keynum=key();
		if(keynum==1)
		{
			Mode=~Mode;//切换模式
		}
		if(Mode==1)
		{
			Timeset();
		}
		else
		{
			Timeshow();
		}
	}
}