#include <REGX52.H>
#include "UARTmessage.h"
#include "LEDcontrol.h"

void main(void)
{
	UART_init();
	while(1);
}

void UART_Rountine() interrupt 4//´®¿ÚÖÐ¶Ïº¯Êý
{
	if(RI==1)
	{
		control_LED(~SBUF);
		RI=0;
		UART_Send(SBUF);
	}
}