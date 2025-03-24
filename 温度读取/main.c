#include <REGX52.H>
#include "LCDtools/lcd1602.h"
#include "DS18B20.h"

void main()
{
	lcd1602_init();
	lcd1602_show_string(0,0,"Temperature:");
	while(1)
	{
		DS18B20_convert();
		lcd1602_show_unsigned_char_temperature(0,1,DS18B20_read());
	}
}