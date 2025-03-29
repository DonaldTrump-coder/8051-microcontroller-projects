#include "LCDtools/lcd1602.h"
#include "XPT2046.h"

unsigned int val;

void main()
{
	LCD_init();
	LCD_showstring(1,1,"ADJ  NTC  RG");
	while(1)
	{
		val=XPT_readAD(XPT_XP);
		LCD_shownum(1,2,val,3);
		val=XPT_readAD(XPT_YP);
		LCD_shownum(6,2,val,3);
		val=XPT_readAD(XPT_VBAT);
		LCD_shownum(11,2,val,3);
	}
}