#include <REGX52.H>
#include "LEDcontrol.h"

void control_LED(unsigned char num)
{
	P2=num;
}