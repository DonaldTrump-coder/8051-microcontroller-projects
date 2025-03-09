#include "timer.h"
#include <REGX52.H>
#include "LCDtools/lcd1602.h"

int counter=0;
unsigned char temp;
unsigned char ten_min='0';
unsigned char min='0';
unsigned char ten_sec='0';
unsigned char sec='0';
void timer0_init()
{
	TMOD=0x01;//定时器工作模式
	TF0=0;
	TR0=1;
	TH0=64535/256;
	TL0=64535%256;
	ET0=1;
	EA=1;
	PT0=0;
}

void clock_init()
{
	lcd1602_clear();
	lcd1602_show_string(0,0,"time:");
	lcd1602_show_string(0,1,"00:00");
}

void clock_show(unsigned char ten_min,
				unsigned char min,
				unsigned char ten_sec,
				unsigned char sec)
{
	lcd1602_show_string(0,1,&ten_min);
	lcd1602_show_string(1,1,&min);
	lcd1602_show_string(2,1,":");
	lcd1602_show_string(3,1,&ten_sec);
	lcd1602_show_string(4,1,&sec);
}

void cut_progress_ms() interrupt 1
{
	timer0_init();
	counter++;
	if(counter>=1000)
	{
		counter=0;
		temp=plus(sec);
		if(sec=='9')
		{
			sec=temp;
			temp=plus(ten_sec);
			if(ten_sec=='5')
			{
				ten_sec='0';
				temp=plus(min);
				if(min=='9')
				{
					min=temp;
					temp=plus(ten_min);
					if(ten_min=='5')
					{
						ten_min='0';
						min='0';
						ten_sec='0';
						sec='0';
						clock_show(ten_min,min,ten_sec,sec);
					}
					else
					{
						ten_min=temp;
						clock_show(ten_min,min,ten_sec,sec);
					}
				}
				else
				{
					min=temp;
					clock_show(ten_min,min,ten_sec,sec);
				}
			}
			else
			{
				ten_sec=temp;
				clock_show(ten_min,min,ten_sec,sec);
			}
		}
		else
		{
			sec=temp;
			clock_show(ten_min,min,ten_sec,sec);
		}
	}
}

unsigned char plus(unsigned char i)
{
	switch(i)
	{
		case '0':return '1';
		case '1':return '2';
		case '2':return '3';
		case '3':return '4';
		case '4':return '5';
		case '5':return '6';
		case '6':return '7';
		case '7':return '8';
		case '8':return '9';
		case '9':return '0';
	}
}

