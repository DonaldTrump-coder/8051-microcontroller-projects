#include "LCD1602.h"

void main()
{
	LCD_init();
	LCD_showchar(1,1,'c');
	LCD_showstring(3,1,"Hello!");
	LCD_shownum(10,1,400,3);
	LCD_showsignednum(1,2,-400,3);
	LCD_showhex(6,2,0x6B);
	while(1)
	{
		
	}
}