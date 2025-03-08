#include <REGX52.H>
#include "LCDtools/lcd1602.h"

void main()
{
	lcd1602_init();
	while(1)
	{
		lcd1602_show_string(0,0,"Allen");
	}
}