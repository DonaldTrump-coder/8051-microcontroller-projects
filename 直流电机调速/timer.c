#include "timer.h"
#include <REGX52.H>

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
