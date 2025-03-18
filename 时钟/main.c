#include <REGX52.H>
#include "LCDtools/lcd1602.h"
#include "DS1302.h"

unsigned char time[]={25,2,3,18,13,12,31};
unsigned char timegot[]={25,2,3,18,13,12,31};

void main()
{
	lcd1602_init();
	DS1302_init();
	lcd1602_show_string(0,0,"Time:");
	Write(0x8E,0x00);//取消写保护
	Delay1ms();
	Writetime(time);
	while(1)
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
}