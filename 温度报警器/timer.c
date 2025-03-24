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
	TL0=0x18;
	TH0=0xFC;
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
